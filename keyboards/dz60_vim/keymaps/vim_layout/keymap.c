#include QMK_KEYBOARD_H



enum my_keycodes {
    KC_E4 = SAFE_RANGE,
    KC_EO,
    KC_DD,
    KC_DW,
    KC_DB,
    KC_D0,
    KC_D4,
    KC_V4,
    KC_V0,
    KC_VW,
    KC_VB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    Base layer
	[0] = LAYOUT_60_iso_split_space_bs_rshift(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT, KC_LSFT, KC_GRV, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RCTL, KC_RSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC, TO(1), TT(4), KC_RGUI, KC_RALT),
//    Vim edit layer
    [1] = LAYOUT_60_iso_split_space_bs_rshift(TO(0), KC_NO, KC_NO, KC_NO, KC_E4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LCTL(KC_A), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_RGHT), KC_NO, KC_NO, KC_NO, LGUI(KC_C), LGUI(KC_Z), TO(0), KC_EO, LGUI(KC_V), KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, TO(2), KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_NO, TO(3), LALT(KC_LEFT), KC_NO, KC_NO, KC_NO, KC_NO, LGUI(KC_F), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, TO(0), KC_NO, KC_NO),
//    Vim delete layer
    [2] = LAYOUT_60_iso_split_space_bs_rshift(TO(1), KC_NO, KC_NO, KC_NO, KC_D4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_D0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DW, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LALT(KC_LEFT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
//    Vim visual layer
    [3] = LAYOUT_60_iso_split_space_bs_rshift(TO(1), KC_NO, KC_NO, KC_NO, KC_V4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_V0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VW, KC_NO, KC_NO, KC_NO, LCTL(KC_C), KC_NO, KC_NO, KC_NO, LCTL(KC_V), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_NO, KC_NO, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_UP), LSFT(KC_RGHT), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_NO, TO(1), KC_VB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
//    Computer controls
	[4] = LAYOUT_60_iso_split_space_bs_rshift(TO(0), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MUTE, KC_MUTE, KC_NO, KC_NO, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_VOLU, KC_NO, KC_WH_R, KC_WH_U, KC_WH_L, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MSTP, KC_MSTP, KC_MSTP, KC_NO, KC_TRNS, KC_NO, KC_NO)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_EO:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("e") SS_TAP(X_ENTER));
                layer_move(0);
            }
            return false; // Skip all further processing of this key
        case KC_DD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("a") SS_LCTL("k") SS_TAP(X_BSPACE));
                layer_move(1);
            }
            return false; // Skip all further processing of this key
        case KC_D0:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_BSPACE)));
                layer_move(1);
            }
            return false; // Skip all further processing of this key
        case KC_DW:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_DEL)));
                layer_move(1);
            }
            return false; // Skip all further processing of this key
        case KC_DB:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_BSPACE)));
                layer_move(1);
            }
            return false; // Skip all further processing of this key
        case KC_V0:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LCTL("a")));
            }
            return false; // Skip all further processing of this key
        case KC_VW:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_RIGHT))));
            }
            return false; // Skip all further processing of this key
        case KC_VB:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_LEFT))));
            }
            return false; // Skip all further processing of this key
//        keys only used in combos
        case KC_E4:
            return false;
        case KC_D4:
            return false; // Skip all further processing of this key
        case KC_V4:
            return false; // Skip all further processing of this key
        default:
            return true; // Process all other keycodes normally
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 1:
            rgblight_enable_noeeprom();
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_TEAL);
            break;
        case 2:
            rgblight_enable_noeeprom();
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        case 3:
            rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
            break;
        case 4:
            rgblight_enable_noeeprom();
            rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_PINK);
            break;

        default: //  for any other layers, or the default layer
            rgblight_disable();
            break;
    }
    return state;
}
void keyboard_pre_init_user(void) {
    rgblight_disable();
}
void keyboard_post_init_user(void) {
    // Call the post init code.
    rgblight_disable();
}