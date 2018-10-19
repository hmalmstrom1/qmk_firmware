/* Copyright 2017 Wunder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"

// Layer shorthand
#define _QW 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
/*

enum custom_keycodes {
  QW = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
}; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | DEL    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | LCTRL  | A      | S      | D      | F      | G      | HOME   | CAPS   | PG UP  | H      | J      | K      | L      | ;      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | ENTER  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | ADJUST | ESC   | LALT   | RGUI    | RAISE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | LOWER  | LEFT   | DOWN   | UP     | RIGHT  |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QW] = { /* QWERTY */
  { KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_GRV,  KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL  },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_BSLS, KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC  },
  { KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HOME, KC_CAPS,  KC_PGUP, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT   },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_END,  KC_UP,   KC_PGDN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT  },
  { MO(_ADJUST), KC_ESC, KC_LALT,  KC_RGUI, MO(_LOWER),  KC_SPC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_SPC,  MO(_RAISE),  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT  },
 },

 /* RAISE 
  * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | `      | F1     | F2     | F3     | F4     | F5     | _      | P/     | P*     | F6     | F7     | F8     | F9     | F10    | BACKSP  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
 * | `      | 1      | 2      | 3      | 4      | 5      | (      | P/     | )      | 6      | 7      | 8      | 9      | 0      | DEL     |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
 * | LCTRL  | F1     | F2     | F3     | F4     | F5     | HOME   |        | PG UP  | F6     | -      | =      | [      | ]      | \       |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
 * | LSHIFT | F7     | F8     | F9     | F10    | F11    | END    | UP     | PG DN  | F12    | ISO #  | ISO /  | .      | /      | ENTER   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+---------|
 * |        | ESC    | LALT   | RGUI   |        | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  |        | LEFT   | DOWN   | UP     | RIGHT   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */       

 [_RAISE] = { /* RAISE */
   { KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MINS, KC_SLSH, KC_ASTR,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC },
   { KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LPRN, KC_SLSH, KC_RPRN,  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,   KC_DEL },
   { KC_LCTL, KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_HOME, KC_CAPS,  KC_PGUP, KC_F6,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS },
   { KC_LSFT, KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_END,  KC_UP,   KC_PGDN,  KC_F12, KC_NUHS, KC_NUBS, KC_DOT,  KC_SLSH, KC_ENT  },
   { _______, KC_ESC, KC_LALT, KC_RGUI, _______, KC_SPC,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_SPC, _______, _______, _______, _______, _______ },
 },

 /* LOWER
  * .--------------------------------------------------------------------------------------------------------------------------------------.
  * | ~      | F1     | F2     | F3     | F4     | F5     | _      | P/     | P*     | F6     | F7     | F8     | F9     | F10    | BACKSP |
  * |--------------------------------------------------------------------------------------------------------------------------------------|
  * | ~      | !      | @      | #      | $      | %      | {      | P/     | }      | ^      | &      | *      | (      | )      | DEL    |
  * |--------------------------------------------------------------------------------------------------------------------------------------|
  * | LCTRL  | F1     | F2     | F3     | F4     | F5     | HOME   |        | PG UP  | F6     | _      | +      | {      | }      | |      |
  * |--------------------------------------------------------------------------------------------------------------------------------------|
  * | LSHIFT | F7     | F8     | F9     | F10    | F11    | END    | UP     | PG DN  | F12    | ISO ~  | ISO |  |        |        |        | 
  * |--------------------------------------------------------------------------------------------------------------------------------------|
  * |        |        |        |        |        |        |        |        |        |        |        | Nexxt  | Vol -  | Vol +  | Play   |
  * '--------------------------------------------------------------------------------------------------------------------------------------'
  */

 [_LOWER] = { /* LOWER */
   { KC_TILD,  KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,    KC_UNDS,  KC_SLSH, KC_ASTR, KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_BSPC },
   { KC_TILD,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_AMPR,  KC_LCBR,  KC_SLSH, KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL },
   { KC_LCTL,  KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,    KC_HOME, KC_CAPS, KC_PGUP, KC_F6,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE },
   { KC_LSFT,  KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_END,   KC_UP,   KC_PGDN, KC_F12, S(KC_NUHS), S(KC_NUBS), _______, _______, _______ },
   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY },
 },

 [_ADJUST] = { /* ADJUST */
   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, KC_DEL  },
   { _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ },
   { RGB_MOD, RGB_RMOD, _______, AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ },
   { RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_HUD, RGB_HUI, _______, _______ },
   { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_SAD, RGB_SAI, RGB_VAI },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
