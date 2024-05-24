#include QMK_KEYBOARD_H
#include "color.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R,
        KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,
        KC_SCLN, KC_QUOT, LSFT_T(KC_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_KB_MUTE, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT,
        KC_SLSH, KC_RSFT, KC_GRV, KC_LALT, KC_LGUI, KC_SPC, TT(1), TT(2), KC_ENT, KC_LBRC, KC_RBRC, KC_EQL
    ),
    [1] = LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_1, KC_2,
        KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12, KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,
        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, KC_TRNS, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,
        KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_WSCH, MO(3), KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
        KC_TRNS, KC_INS, KC_PSCR, KC_APP, KC_NO, KC_NO, KC_PGUP, LCTL(KC_LEFT), KC_UP, LCTL(KC_RGHT), LCTL(KC_BSPC),
        KC_NO, KC_TRNS, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_NO,
        KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_HOME, KC_NO, KC_END,
        KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO, DF(0),
        KC_NO, CG_TOGG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, CG_TOGG, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS
    )
};

#if ENCODER_ENABLE
#    ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [1] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [2] = {ENCODER_CCW_CW(KC_BRMD, KC_BRMU), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
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

// static uint16_t timer;
// static uint16_t current_index;

void keyboard_post_init_user(void) {
    // Call the post init code.
    // timer = timer_read();

#ifdef RGB_MATRIX_ENABLE
    // set colors at boot time
    // rgb_matrix_enable_noeeprom();
    // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    // rgb_matrix_sethsv_noeeprom(HSV_OFF);

    // rgb_matrix_set_color(current_index, RGB_RED);
#endif
}

// #ifdef RGB_MATRIX_ENABLE
// bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//     // lighting
//     if (timer_elapsed(timer) >= 250) {
//         rgb_matrix_set_color(current_index, RGB_OFF);
//         current_index = (current_index + 1) % RGB_MATRIX_LED_COUNT;
//         rgb_matrix_set_color(current_index, RGB_RED);
//         timer = timer_read();
//     }
//     return false;
// }
// #endif

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
