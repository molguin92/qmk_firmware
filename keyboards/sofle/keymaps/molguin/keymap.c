#include "keycodes.h"
#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬───┬──────┬──────┬─────┐                     ┌───┬───┬───┬───┬───┬──────┐
//    │ esc  │ 1 │ 2 │  3   │  4   │  5  │                     │ 6 │ 7 │ 8 │ 9 │ 0 │ bspc │
//    ├──────┼───┼───┼──────┼──────┼─────┤                     ├───┼───┼───┼───┼───┼──────┤
//    │ tab  │ q │ w │  e   │  r   │  t  │                     │ y │ u │ i │ o │ p │  \   │
//    ├──────┼───┼───┼──────┼──────┼─────┤                     ├───┼───┼───┼───┼───┼──────┤
//    │ lctl │ a │ s │  d   │  f   │  g  │                     │ h │ j │ k │ l │ ; │  '   │
//    ├──────┼───┼───┼──────┼──────┼─────┼─────────┐   ┌───────┼───┼───┼───┼───┼───┼──────┤
//    │ lsft │ z │ x │  c   │  v   │  b  │ kB_MUTE │   │       │ n │ m │ , │ . │ / │ rsft │
//    └──────┴───┼───┼──────┼──────┼─────┼─────────┤   ├───────┼───┼───┼───┼───┼───┴──────┘
//               │ ` │ lalt │ lgui │ spc │  TT(1)  │   │ TT(2) │ [ │ ] │ - │ = │
//               └───┴──────┴──────┴─────┴─────────┘   └───────┴───┴───┴───┴───┘
[0] = LAYOUT(
  KC_ESC  , KC_1 , KC_2   , KC_3    , KC_4    , KC_5   ,                          KC_6    , KC_7    , KC_8    , KC_9   , KC_0    , KC_BSPC     ,
  KC_TAB  , KC_Q , KC_W   , KC_E    , KC_R    , KC_T   ,                          KC_Y    , KC_U    , KC_I    , KC_O   , KC_P    , KC_BACKSLASH,
  KC_LCTL , KC_A , KC_S   , KC_D    , KC_F    , KC_G   ,                          KC_H    , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT     ,
  KC_LSFT , KC_Z , KC_X   , KC_C    , KC_V    , KC_B   , KC_KB_MUTE ,     KC_NO , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT     ,
                   KC_GRV , KC_LALT , KC_LGUI , KC_SPC , TT(1)      ,     TT(2) , KC_LBRC , KC_RBRC , KC_MINS , KC_EQL
),

//    ┌───┬────┬────┬────┬────┬────┐                    ┌───────┬────┬────┬────┬─────┬─────┐
//    │ ` │ f1 │ f2 │ f3 │ f4 │ f5 │                    │  f6   │ f7 │ f8 │ f9 │ f10 │ f11 │
//    ├───┼────┼────┼────┼────┼────┤                    ├───────┼────┼────┼────┼─────┼─────┤
//    │ ▽ │ 1  │ 2  │ 3  │ 4  │ 5  │                    │   6   │ 7  │ 8  │ 9  │  0  │ f12 │
//    ├───┼────┼────┼────┼────┼────┤                    ├───────┼────┼────┼────┼─────┼─────┤
//    │ ▽ │ !  │ @  │ #  │ $  │ %  │                    │   ^   │ &  │ *  │ (  │  )  │  |  │
//    ├───┼────┼────┼────┼────┼────┼───┐   ┌────────────┼───────┼────┼────┼────┼─────┼─────┤
//    │ ▽ │ =  │ -  │ +  │ {  │ }  │ ▽ │   │     ▽      │   [   │ ]  │ ;  │ :  │  \  │ ent │
//    └───┴────┼────┼────┼────┼────┼───┤   ├────────────┼───────┼────┼────┼────┼─────┴─────┘
//             │ ▽  │ ▽  │ ▽  │ ▽  │ ▽ │   │ www_search │ MO(3) │ ▽  │ ▽  │ ▽  │
//             └────┴────┴────┴────┴───┘   └────────────┴───────┴────┴────┴────┘
[1] = LAYOUT(
  KC_GRV  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                         KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
  KC_TRNS , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_F12  ,
  KC_TRNS , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,                         KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_PIPE ,
  KC_TRNS , KC_EQL  , KC_MINS , KC_PLUS , KC_LCBR , KC_RCBR , KC_TRNS ,     KC_TRNS , KC_LBRC , KC_RBRC , KC_SCLN , KC_COLN , KC_BSLS , KC_ENTER,
                      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_WSCH , MO(3)   , KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌───┬─────────┬─────────┬─────────┬─────────┬───────┐           ┌──────┬────────────┬──────┬────────────┬────────────┬─────┐
//    │ ▽ │    ▽    │    ▽    │    ▽    │    ▽    │   ▽   │           │  ▽   │     ▽      │  ▽   │     ▽      │     ▽      │ del │
//    ├───┼─────────┼─────────┼─────────┼─────────┼───────┤           ├──────┼────────────┼──────┼────────────┼────────────┼─────┤
//    │ ▽ │   ins   │  pscr   │   app   │         │       │           │ pgup │ LCTL(left) │  up  │ LCTL(rght) │ LCTL(bspc) │     │
//    ├───┼─────────┼─────────┼─────────┼─────────┼───────┤           ├──────┼────────────┼──────┼────────────┼────────────┼─────┤
//    │ ▽ │  lalt   │  lctl   │  lsft   │         │ caps  │           │ pgdn │    left    │ down │    rght    │            │ ent │
//    ├───┼─────────┼─────────┼─────────┼─────────┼───────┼───┐   ┌───┼──────┼────────────┼──────┼────────────┼────────────┼─────┤
//    │ ▽ │ LCTL(z) │ LCTL(x) │ LCTL(c) │ LCTL(v) │       │ ▽ │   │ ▽ │      │    home    │      │    end     │            │ ent │
//    └───┴─────────┼─────────┼─────────┼─────────┼───────┼───┤   ├───┼──────┼────────────┼──────┼────────────┼────────────┴─────┘
//                  │    ▽    │    ▽    │    ▽    │ MO(3) │ ▽ │   │ ▽ │  ▽   │     ▽      │  ▽   │     ▽      │
//                  └─────────┴─────────┴─────────┴───────┴───┘   └───┴──────┴────────────┴──────┴────────────┘
[2] = LAYOUT(
  KC_TRNS , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS ,                         KC_TRNS , KC_TRNS       , KC_TRNS , KC_TRNS       , KC_TRNS       , KC_DEL  ,
  KC_TRNS , KC_INS     , KC_PSCR    , KC_APP     , KC_NO      , KC_NO   ,                         KC_PGUP , LCTL(KC_LEFT) , KC_UP   , LCTL(KC_RGHT) , LCTL(KC_BSPC) , KC_NO   ,
  KC_TRNS , KC_LALT    , KC_LCTL    , KC_LSFT    , KC_NO      , KC_CAPS ,                         KC_PGDN , KC_LEFT       , KC_DOWN , KC_RGHT       , KC_NO         , KC_ENTER,
  KC_TRNS , LCTL(KC_Z) , LCTL(KC_X) , LCTL(KC_C) , LCTL(KC_V) , KC_NO   , KC_TRNS ,     KC_TRNS , KC_NO   , KC_HOME       , KC_NO   , KC_END        , KC_NO         , KC_ENTER,
                         KC_TRNS    , KC_TRNS    , KC_TRNS    , MO(3)   , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS       , KC_TRNS , KC_TRNS
),

//    ┌─────────┬───┬───────┬───┬───┬───┐           ┌───┬──────┬──────┬──────┬───┬───┐
//    │         │   │       │   │   │   │           │   │      │      │      │   │   │
//    ├─────────┼───┼───────┼───┼───┼───┤           ├───┼──────┼──────┼──────┼───┼───┤
//    │ QK_BOOT │   │ DF(0) │   │   │   │           │   │      │      │      │   │   │
//    ├─────────┼───┼───────┼───┼───┼───┤           ├───┼──────┼──────┼──────┼───┼───┤
//    │         │   │       │   │   │   │           │   │ vold │ mute │ volu │   │   │
//    ├─────────┼───┼───────┼───┼───┼───┼───┐   ┌───┼───┼──────┼──────┼──────┼───┼───┤
//    │         │   │       │   │   │   │   │   │   │   │ mprv │ mply │ mnxt │   │   │
//    └─────────┴───┼───────┼───┼───┼───┼───┤   ├───┼───┼──────┼──────┼──────┼───┴───┘
//                  │   ▽   │ ▽ │ ▽ │ ▽ │ ▽ │   │ ▽ │ ▽ │  ▽   │  ▽   │  ▽   │
//                  └───────┴───┴───┴───┴───┘   └───┴───┴──────┴──────┴──────┘
[3] = LAYOUT(
  KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                         KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO,
  QK_BOOT , KC_NO , DF(0)   , KC_NO   , KC_NO   , KC_NO   ,                         KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO,
  KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                         KC_NO   , KC_VOLD , KC_MUTE , KC_VOLU , KC_NO , KC_NO,
  KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,     KC_NO   , KC_NO   , KC_MPRV , KC_MPLY , KC_MNXT , KC_NO , KC_NO,
                    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
)
};
// clang-format on

// #if ENCODER_ENABLE
// #    ifdef ENCODER_MAP_ENABLE
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
//     [0] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
//     [1] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
//     [2] = {ENCODER_CCW_CW(KC_BRMD, KC_BRMU), ENCODER_CCW_CW(RGB_HUI, RGB_HUD)},
//     [3] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}
// };
// #    else
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     switch (get_highest_layer(layer_state)) {
//         default:
//             if (index == 0) {
//                 if (clockwise) {
//                     tap_code(KC_VOLU);
//                 } else {
//                     tap_code(KC_VOLD);
//                 }
//             } else if (index == 1) {
//                 if (clockwise) {
//                     tap_code(KC_PGUP);
//                 } else {
//                     tap_code(KC_PGDN);
//                 }
//             }
//             break;
//     }
//     return false;
// }
// #    endif
// #endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    oled_off();
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

// void print_hue(void) {
//     // if (get_highest_layer(layer_state) <= 0) {
//     //     // only print if a layer key is pressed
//     //     return;
//     // }
//
//     oled_write_ln_P(PSTR("Hue:\n"), false);
//
//     uint8_t hue = rgb_matrix_get_hue();
//     char hue_str[3];
//     sprintf(hue_str, "%03d", hue);
//     oled_write_raw(hue_str, false);
// }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status();
    } else {
        // should probably blink or scroll to avoid burn-in
        // print_hue();
    }
    return false;
}
#endif
