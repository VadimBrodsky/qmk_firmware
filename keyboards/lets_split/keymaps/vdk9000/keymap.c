#include "lets_split.h"
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
#define _MOUSE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MOUSE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |      | Alt  |Lower |    Space    |Raise |Leader|      |      |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  KC_LCTL, KC_LGUI, _______, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEAD, _______, _______, KC_ENT   \
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
  KC_TILD,    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______,   KC_INSERT,  _______, _______, KC_DEL, \
  LCTL(KC_A), KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_MINS, KC_HOME, KC_PGDOWN, KC_PGUP,    KC_END,  _______, KC_PIPE, \
  KC_LCBR,    _______, _______, _______, KC_EQL,  KC_UNDS, _______, _______,   _______,    _______, _______, KC_RCBR, \
  _______,    _______, _______, _______, _______, _______, _______, _______,   _______,    _______, _______, _______  \
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
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |Speed1|Speed2|Speed3|      |      |      | WhlUp|      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |WhlDwn|      |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Mouse Click |      |      |      |      |Click2|
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = KEYMAP( \
  _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, KC_WH_U, _______, _______, _______, _______, \
  _______, _______, _______, KC_WH_D, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, KC_BTN1, KC_BTN1, _______, _______, _______, _______, KC_BTN2  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F11 |  F12 |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,  \
  _______, KC_F11,  KC_F12,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
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
      register_code(KC_LSFT);
      register_code(KC_SYSTEM_SLEEP);
      unregister_code(KC_SYSTEM_SLEEP);
      unregister_code(KC_LSFT);
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
  }
}

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
