/*
Copyright (c) 2014-2015 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

// Include guard
#pragma once

#include <Arduino.h>
#include "PluggableUSB.h"
#include "HID.h"
#include "HID-Settings.h"

#include "HIDTables.h"
#include "HIDAliases.h"
#include "ASCIIMap.h"

// We have a max USB_EP_SIZE of 64 on the 32u4. The previous implementation
// was built around the assumption that it needed to work on simpler, more
// resource constrained MCUs, so it was careful to fit everything into a 16 byte
// endpoint size. As we improve our implementation, we can bump it up a bit.

// Put another way, this comment is now incorrect:  Max value for USB EP_SIZE 16
// +1 reportID, +1 modifier, +1 custom key
#define NKRO_KEY_COUNT (8*13)

typedef union {
    // Modifier + keymap + 1 custom key
    uint8_t whole8[];
    uint16_t whole16[];
    uint32_t whole32[];
    struct {
        uint8_t modifiers;
        uint8_t keys[NKRO_KEY_COUNT / 8];
        uint8_t key;
    };
    uint8_t allkeys[2 + NKRO_KEY_COUNT / 8];
} HID_KeyboardReport_Data_t;



class Keyboard_ : public Print {
  public:
    Keyboard_(void);
    void begin(void);
    void end(void);

    size_t press(uint8_t k);
    size_t release(uint8_t k);
    size_t releaseAll(void);
    int sendReport(void);
    size_t write(uint8_t k);

  protected:
    HID_KeyboardReport_Data_t _keyReport;

};
extern Keyboard_ Keyboard;

