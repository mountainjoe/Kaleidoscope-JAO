/* -*- mode: c++ -*-
   Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreusy
   Copyright (C) 2018, 2019  Keyboard.io, Inc

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-Redial.h"

/* -*- mode: c++ -*-
   Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
   defined as part of the USB HID Keyboard specification. You can find the names
   (if not yet the explanations) for all the standard `Key_` defintions offered by
   Kaleidoscope in these files:
      https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
      https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
      https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
      https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h

   Additional things that should be documented here include:
     using ___ to let keypresses fall through to the previously active layer
     using XXX to mark a keyswitch as 'blocked' on this layer
     keeping NUM and FN consistent and accessible on all layers
*/

#define MO(n) ShiftToLayer(n)

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At LSHIFT(Key_2)
#define Key_Octothorpe LSHIFT(Key_3)
#define Key_Dollar LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret LSHIFT(Key_6)
#define Key_And LSHIFT(Key_7)
#define Key_Star LSHIFT(Key_8)
#define Key_LeftParens LSHIFT(Key_9)
#define Key_RightParens LSHIFT(Key_0)
#define Key_Plus LSHIFT(DV_EQL)
#define Key_Colon LSHIFT(DV_SCLN)
#define Key_Pipe LSHIFT(DV_BSLS)
#define Key_Pound Key_KeypadPoundSign
#define Key_Underscore LSHIFT(DV_MINS)
#define Key_Tilde LSHIFT(DV_GRV)
#define DV_LCBR LSHIFT(DV_LBRC)
#define DV_RCBR LSHIFT(DV_RBRC)

#define Key_PrevTrack Consumer_ScanPreviousTrack
#define Key_NextTrack Consumer_ScanNextTrack
#define Key_PlayPause Consumer_PlaySlashPause
#define Key_Stop Consumer_Stop
#define Key_VolumeDown Consumer_VolumeDecrement
#define Key_VolumeUp Consumer_VolumeIncrement
#define Key_Mute Consumer_Mute
#define Key_BrightDn Consumer_DisplayBrightnessDecrement
#define Key_BrightUp Consumer_DisplayBrightnessIncrement


enum {
  DVORAK,
  MEDIA,
  NAV,
  MOUSE,
  SYM,
  NUM,
  FN
};


/* *INDENT-OFF* */
KEYMAPS(  
  [DVORAK] = KEYMAP_STACKED
  (
      // Left
      DV_QUOT,         DV_COMM,             DV_DOT,               DV_P,           DV_Y,
      DV_A,            DV_O,                DV_E,                 DV_U,           DV_I,
      DV_SCLN,         DV_Q,                DV_J,                 DV_K,           DV_X,            XXX,
      XXX,             XXX,                 XXX,                  Key_Esc,        Key_Space,       Key_Tab,

      // Right
                       DV_F,                DV_G,                 DV_C,           DV_R,            DV_L,
                       DV_D,                DV_H,                 DV_T,           DV_N,            DV_S,
      XXX,             DV_B,                DV_M,                 DV_W,           DV_V,            DV_Z,
      Key_Backspace,   Key_Enter,           Key_Delete,           XXX,            XXX,             XXX
  ),

  [MEDIA] = KEYMAP_STACKED
  (
      // Left
      XXX,             XXX,                  XXX,                   XXX,             XXX,
      Key_LeftGui,     Key_LeftControl,      Key_LeftAlt,           Key_LeftShift,   XXX,
      XXX,             XXX,                  XXX,                   XXX,             XXX,              ___,
      ___,             ___,                  ___,                   XXX,             XXX,              XXX,

      // Right
                       XXX,                  XXX,                   XXX,                        XXX,                         XXX,
                       XXX,                  Key_PrevTrack,         Key_VolumeDown,             Key_VolumeUp,                Key_NextTrack,
      ___,             XXX,                  XXX,                   Key_BrightDn,               Key_BrightUp,                XXX,
      Key_Stop,        Key_PlayPause,        Key_Mute,              ___,                        ___,                         ___

  ),

  [NAV] = KEYMAP_STACKED
  (
     // Left
      XXX,             XXX,                  XXX,                   XXX,             XXX,
      Key_LeftGui,     Key_LeftControl,      Key_LeftAlt,           Key_LeftShift,   XXX,
      XXX,             XXX,                  XXX,                   XXX,             XXX,              ___,
      ___,             ___,                  ___,                   XXX,             XXX,              XXX,


      // Right
                       XXX,                  XXX,                   XXX,             XXX,              XXX,
                       Key_CapsLock,         Key_LeftArrow,         Key_DownArrow,   Key_UpArrow,      Key_RightArrow,
      ___,             Key_Insert,           Key_Home,              Key_PageDown,    Key_PageUp,       Key_End,
      ___,             ___,                  Key_mouseBtnP,         Key_mouseBtnN,   ___,              ___
   ),

  [MOUSE] = KEYMAP_STACKED
  (
      // Left
      XXX,             XXX,                  XXX,                   XXX,             XXX,
      Key_LeftGui,     Key_LeftControl,      Key_LeftAlt,           Key_LeftShift,   XXX,
      XXX,             XXX,                  XXX,                   XXX,             XXX,              ___,
      XXX,             XXX,                  XXX,                   ___,             ___,              ___,

      // Right
                       XXX,                  Key_mouseWarpNW,       XXX,               XXX,                Key_mouseWarpNE,
                       XXX,                  Key_mouseL,            Key_mouseDn,       Key_mouseUp,        Key_mouseR,
      ___,             XXX,                  Key_mouseWarpSW,       Key_mouseScrollDn, Key_mouseScrollUp,  Key_mouseWarpSE,
      Key_mouseBtnM,   Key_mouseBtnL,        Key_mouseBtnR,         ___,               ___,                ___
  ),

  [SYM] = KEYMAP_STACKED
  (
      // Left
      XXX,        XXX,      DV_LCBR,            DV_RCBR,           XXX,
      DV_GRV,     XXX,      Key_LeftParen,      Key_RightParen,    XXX,
      XXX,        XXX,      DV_LBRC,            DV_RBRC,           XXX,                 XXX,
      XXX,        XXX,      XXX,                XXX,               Key_Underscore,      XXX,

      // RIGHT
                       XXX,                  XXX,                   XXX,             XXX,              XXX,
                       XXX,                  Key_LeftShift,         Key_LeftAlt,     Key_LeftControl,  Key_LeftGui,
      ___,             XXX,                  XXX,                   XXX,             XXX,              XXX,
      XXX,             XXX,                  XXX,                   ___,             ___,              ___
   ),

   [NUM] = KEYMAP_STACKED
   (
      // Left
      XXX,             XXX,                  XXX,                   XXX,             XXX,
      Key_LeftGui,     Key_LeftControl,      Key_LeftAlt,           Key_LeftShift,   XXX,
      XXX,             XXX,                  XXX,                   XXX,             XXX,              ___,
      XXX,             XXX,                  XXX,                   ___,             ___,              ___,

      // RIGHT
                        XXX,               Key_7,         Key_8,        Key_9,           DV_SLSH,
                        Key_Semicolon,     Key_4,         Key_5,        Key_6,           DV_MINS,
      Key_Backtick,     XXX,               Key_1,         Key_2,        Key_3,           Key_Backslash,
      ___,              DV_DOT,            Key_0,         DV_EQL,       ___,             ___
    ),

   [FN] = KEYMAP_STACKED
   (
     // Left
      Key_F12,       Key_F7,               Key_F8,                Key_F9,             Key_PrintScreen,
      Key_F11,       Key_F4,               Key_F5,                Key_F6,             Key_ScrollLock,
      Key_F10,       Key_F1,               Key_F2,                Key_F3,             Key_Pause,       ___,
      ___,           ___,                  Key_PcApplication,     ___,                ___,             ___,
 
      // RIGHT
                       XXX,                  XXX,                   XXX,             XXX,              XXX,
                       XXX,                  Key_LeftShift,         Key_LeftAlt,     Key_LeftControl,  Key_LeftGui,
      ___,             XXX,                  XXX,                   XXX,             XXX,              XXX,
      XXX,             XXX,                  XXX,                   ___,             ___,              ___
    )

)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  Qukeys,
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  MouseKeys,
  Redial
);

bool kaleidoscope::plugin::Redial::shouldRemember(Key mapped_key) {
  if (mapped_key >= Key_A && mapped_key <= Key_Z)
    return true;
  return false;
}



void setup() {
  Kaleidoscope.setup();

  EEPROMKeymap.setup(10);

  QUKEYS(
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 0), Key_LeftGui),      // A / MacCommand
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 1), Key_LeftAlt),      // O / Alt
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 2), Key_LeftControl),  // E / Control
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 3), Key_LeftShift),    // U / Shift
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 1), Key_RightAlt),     // I / AltGr

    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 3), MO(NAV)),        // Esc / Nav
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 4), MO(NUM)),          // Space / Num
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 5), MO(MOUSE)),          // Tab / Mouse

    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 8), Key_LeftShift),    // H / Shift
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 9), Key_LeftControl),  // T / Control
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 10), Key_LeftAlt),     // N / Alt
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 11), Key_LeftGui),     // S / MacCommand

//  kaleidoscope::plugin::Qukey(0, KeyAddr(3, 6), MO()),          // Enter / ??
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 7), MO(SYM)),          // Backspace / Symbols
//  kaleidoscope::plugin::Qukey(0, KeyAddr(3, 8), MO())            // Delete / ??
  )

  MouseKeys.accelDelay = 10;
  MouseKeys.speedDelay = 0;
  MouseKeys.speed = 2;
  MouseKeys.setSpeedLimit(42);
  MouseKeys.wheelDelay = 100;
}

void loop() {
  Kaleidoscope.loop();
}
