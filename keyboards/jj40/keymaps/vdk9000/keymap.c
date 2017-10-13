/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "jj40.h"
#include "action_layer.h"
#include "rgblight.h"

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI | Mouse| Alt  |Lower |    Space    |Raise |Leader|      |      |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  KC_LCTL, KC_LGUI, _______, KC_LALT, MO(_LOWER),  KC_SPC,  MO(_RAISE),   KC_LEAD, _______, _______, KC_ENT   \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |  #   |  $   |   %  |      |      |Insert|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |TmuxPr|   ^  |   &  |  *   |  +   |  -   | Home |PgDown| PgUp | End  |      |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   {  |      |      |      |  =   |  _   |      |      |      |      |      |  }   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______,   KC_INSERT,  _______, _______, KC_DEL,  \
  LCTL(KC_A), KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_MINS, KC_HOME, KC_PGDOWN, KC_PGUP,    KC_END,  _______, KC_PIPE, \
  KC_LCBR,    _______, _______, _______, KC_EQL,  KC_UNDS, _______, _______,   _______,    _______, _______, KC_RCBR, \
  _______,    _______, _______, _______, _______,      _______,     _______,   _______,    _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |  4   |  5   |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   6  |   7  |  8   |  9   |  0   | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   [  |      |      |      |      |      |      |      |      |      |  \   |  ]   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, _______, _______, KC_BSPC, \
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  KC_LBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_RBRC, \
  _______, _______, _______, _______, _______,     _______,      _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
)
};
