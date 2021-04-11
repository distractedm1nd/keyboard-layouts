#include QMK_KEYBOARD_H
#include "quantum/keymap_extras/keymap_us_international_linux.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _SPMOD 3
#define _MOUSEMOD 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SPMOD,
  MOUSEMOD,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ~   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | | \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | [ {  |Lower |Space |Space |Raise | ] }  | GUI  | Alt  |Ctrl  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,               KC_1,    KC_2,    KC_3,                   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,                   KC_9,    KC_0,    KC_BSPC, \
  US_TILD,              KC_Q,    KC_W,    KC_E,                   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,                   KC_O,    KC_P,    KC_BSLS, \
  LT(_SPMOD, KC_TAB),   KC_A,    KC_S,    KC_D,                   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,                   KC_L,    KC_SCLN, US_QUOT, \
  KC_LSFT,              KC_Z,    KC_X,    KC_C,                   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,                KC_DOT,  KC_SLSH, KC_ENT, \
  KC_LCTL,              KC_LALT, KC_LGUI, LT(_MOUSEMOD, KC_LBRC), LOWER,   KC_SPC,  KC_SPC,  RAISE,   LT(_MOUSEMOD, KC_RBRC), KC_RGUI, KC_RALT, KC_RCTL \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |Fullsc|      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | Term |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Prev |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  US_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,     KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  _______, _______, _______, _______, LGUI(KC_F), _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, LGUI(KC_ENT),  \
  _______, _______, _______, KC_MPRV, _______,    _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|RGB Tg|RGB Md|Hue Up|Hue Dn|Sat Up|Sat Dn|Val Up|Val Dn|      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, KC_DEL,  \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

 /* Space/Tab Modifier
 * ,-----------------------------------------------------------------------------------.
 * |      | WS1  | WS2  | WS3  | WS4  | WS5  | WS6  | WS7  | WS8  | WS9  | WS10 | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Sleep |      |      |      |      |      |   Ü  |      |   Ö  |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Ä   |  ß   | HOME | END  |      |      | LEFT |  UP  | DOWN | RIGHT|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | TERM |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Last |      |Albert|Albert|      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_SPMOD] = LAYOUT( \
  _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),      LGUI(KC_6),       LGUI(KC_7), LGUI(KC_8), LGUI(KC_9),  LGUI(KC_0), KC_DEL,  \
  _______, KC_SLEP, _______, _______, _______, _______,      _______,       US_UDIA, _______, US_ODIA,  _______, KC_DEL,  \
  _______, US_ADIA, US_SS,   KC_HOME, KC_END,  _______,      KC_LEFT,       KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______,      _______,       _______, _______, _______,  _______, _______, \
  _______, _______, _______, KC_MPRV, _______, LGUI(KC_SPC), LGUI(KC_SPC),  _______, KC_MNXT, KC_VOLD,  KC_VOLU, KC_MPLY  \
),

 /* Mouse Modifier
 * ,-----------------------------------------------------------------------------------.
 * |      |Accel1|Accel2|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |WheelU|WheelD|      |      | LEFT |  UP  | DOWN | RIGHT|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |LClick|RClick|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSEMOD] = LAYOUT( \
  _______, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, KC_WH_U, KC_WH_D, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______, _______,  _______  \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case SPMOD:
      if (record->event.pressed) {
        layer_on(_SPMOD);
      } else {
        layer_off(_MOUSEMOD);
      }
      return false;
      break;
    case MOUSEMOD:
      if (record->event.pressed) {
        layer_on(_MOUSEMOD);
      } else {
        layer_off(_MOUSEMOD);
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
