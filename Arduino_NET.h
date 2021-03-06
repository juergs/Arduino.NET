/*
 *   This file is part of Arduino.NET
 *
 *   Arduino.NET is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Arduino.NET is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Arduino.NET.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef Arduino_NET_h
#define Arduino_NET_h

#define BUFFERSIZE        64
#define END_MESSAGE       0x23 // #
#define ESCAPE_CHARACTER  0x5C // \

#include "WProgram.h"
#include <inttypes.h>

extern "C" {
  typedef void (*messageCompleteCallback)(byte command, int argc, char** argv);
}

class Arduino_NET {
  public:
    Arduino_NET(void);
    void attach(messageCompleteCallback func);
    void begin(int baud = 9600);
    int available();
    void process();
    void sendCommand(byte command, int count, int first, ...);
    void sendCommand(byte command, int count, const char* first, ...);
    void sendCommand(byte command);
  private:
    char** splitArgs(char *list);
    messageCompleteCallback currentCallback;
    char buffer[BUFFERSIZE];
    int bufferIndex;
    int argCount;
};

extern Arduino_NET Arduino;

#endif
