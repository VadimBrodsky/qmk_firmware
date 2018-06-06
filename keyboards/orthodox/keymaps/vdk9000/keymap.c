/*
This is the keymap for the keyboard

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

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

#include "orthodox.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

//Tap Dance Declarations
enum {
  CT_CLN = 0,
  TD_TC
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define LS__SPC MT(MOD_LSFT, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------.                                         ,-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |                                         |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|      ,---------------------------.      |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |      |Shift | GUI  |Leader| Shift|      |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctl  |   Z  |   X  |   C  |   V  |   B  |Lower | Alt  | Spc  | Spc  |      | Raise|   N  |   M  |   ,  |   .  |   /  |Enter |
 * `-----------------------------------------------------------------------------------------------------------------------------'
 */
  [_QWERTY] = KEYMAP( \
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                           KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,    KC_BSPC, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_LSPO,   KC_LGUI, KC_LEAD, KC_RSPC,         KC_H,    KC_J,    KC_K,    KC_L,      KC_SCLN, KC_QUOT, \
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   LOWER,    KC_LALT,   KC_SPC,  KC_SPC,  _______,  RAISE, KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLSH, KC_ENT  \
  ),

/* Lower
 * ,-----------------------------------------.                                         ,-----------------------------------------.
 * |  ~   |   !  |   @  |   #  |   $  |   %  |                                         |      |      |Insert|      |      | Del  |
 * |------+------+------+------+------+------|      ,---------------------------.      |------+------+------+------+------+------|
 * |      |   ^  |   &  |   *  |   _  |   =  |      |      |      |      |      |      | Home |PgDown| PgUp | End  |      |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   {  |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |  }   |
 * `-----------------------------------------------------------------------------------------------------------------------------'
 */
  [_LOWER] = KEYMAP( \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                                       _______, _______,   KC_INSERT, _______, _______, KC_DEL,  \
    _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_EQL,           _______, _______, _______, _______,          KC_HOME, KC_PGDOWN, KC_PGUP,   KC_END,  _______, KC_PIPE, \
    KC_LCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______, _______, KC_RCBR  \
  ),

/* Raise
 * ,-----------------------------------------.                                         ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                                         |      |      |      |   -  |  +   | Bksp |
 * |------+------+------+------+------+------|      ,---------------------------.      |------+------+------+------+------+------|
 * |      |   6  |   7  |   8  |   9  |   0  |      |      |      |      |      |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   [  |      |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |  \   |  ]   |
 * `-----------------------------------------------------------------------------------------------------------------------------'
 */
  [_RAISE] = KEYMAP( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                          _______, _______, _______, KC_MINS, KC_PLUS, KC_BSPC, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             _______, _______, _______, _______,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    KC_LBRC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_BSLS, KC_RBRC  \
  ),

/* Adjust
 * ,-----------------------------------------.                                         ,-----------------------------------------.
 * |Reset |  F1  |  F2  |  F3  |  F4  |  F5  |                                         |  F6  |  F7  |  F8  |  F9  | F10  | Del  |
 * |------+------+------+------+------+------|      ,---------------------------.      |------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------------------------------------------------'
 */
  [_ADJUST] =  KEYMAP( \
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
    _______, KC_F11,  KC_F12,  _______, _______, _______,          _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  )


};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

LEADER_EXTERNS();
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // OSX Lock
    SEQ_TWO_KEYS(KC_M, KC_L) {
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_Q);
      unregister_code(KC_Q);
      unregister_code(KC_LALT);
      unregister_code(KC_LCTL);
    }

    // OSX Screenshot
    SEQ_TWO_KEYS(KC_M, KC_S) {
      register_code(KC_LSFT);
      register_code(KC_LALT);
      register_code(KC_4);
      unregister_code(KC_4);
      unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
    }

    // OSX Screenshot
    SEQ_TWO_KEYS(KC_M, KC_V) {
      register_code(KC_LALT);
      register_code(KC_F5);
      unregister_code(KC_F5);
      unregister_code(KC_LALT);
    }
  }
}

void dance_cln_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_RSFT);
    register_code (KC_SCLN);
  } else {
    register_code (KC_SCLN);
  }
}

void dance_cln_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_RSFT);
    unregister_code (KC_SCLN);
  } else {
    unregister_code (KC_SCLN);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset),
  [TD_TC]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_LCTL)
  // Other declarations would go here, separated by commas, if you have them
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
