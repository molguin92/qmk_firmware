#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, // row 1
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BACKSLASH, // row 2
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, // row 3
        KC_LEFT_SHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_KB_MUTE, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RIGHT_SHIFT, // row 4
        KC_GRV, KC_LALT, KC_LGUI, KC_SPC, TT(1), TT(2), KC_LBRC, KC_RBRC, KC_MINS ,KC_EQL // row 5
    ),
    [1] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, // row 1
        KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12, // row 2
        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, // row 3
        KC_TRNS, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_ENTER, // row 4
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WSCH, MO(3), KC_TRNS, KC_TRNS, KC_TRNS // row 5
    ),
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, // row 1
        KC_TRNS, KC_INS, KC_PSCR, KC_APP, KC_NO, KC_NO, KC_PGUP, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), LCTL(KC_BSPC), KC_NO, // row 2
        KC_TRNS, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, // row 3
        KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_HOME, KC_NO, KC_END, KC_NO, KC_ENTER, // row 4
        KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS // row 5
    ),
    [3] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, // row 1
        KC_NO, KC_NO, QK_BOOT, KC_NO, DF(0), KC_NO, CG_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, // row 2
        KC_NO, KC_NO, KC_NO, KC_NO, CG_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, // row 3
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, // row 4
        KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS // row 5
    )
};

#if ENCODER_ENABLE
#    ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [1] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [2] = {ENCODER_CCW_CW(KC_BRMD, KC_BRMU), ENCODER_CCW_CW(RGB_HUI, RGB_HUD)},
    [3] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}
};
#    else
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        default:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
            } else if (index == 1) {
                if (clockwise) {
                    tap_code(KC_PGUP);
                } else {
                    tap_code(KC_PGDN);
                }
            }
            break;
    }
    return false;
}
#    endif
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}

void print_status(void) {
    switch (get_highest_layer(layer_state)) {
        case 1:
            oled_write_ln_P(PSTR("Mod\nAlt"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("Mod\nSpec"), false);
            break;
        case 3:
            oled_write_ln_P(PSTR("Mod\nSys"), false);
        default:
            oled_write_ln_P(PSTR("\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("     "), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status();
    } else {
        // should probably blink or scroll to avoid burn-in
        // render_img();
    }
    return false;
}
#endif
