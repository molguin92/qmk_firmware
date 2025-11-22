// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "keycodes.h"
#include QMK_KEYBOARD_H

enum sofle_layers {
    _BASE,
    _L1,
    _L2,
    _L3,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬───┬───┬──────┬──────┬─────┐                       ┌───┬───┬───┬───┬───┬──────┐
//    │ esc  │ 1 │ 2 │  3   │  4   │  5  │                       │ 6 │ 7 │ 8 │ 9 │ 0 │ bspc │
//    ├──────┼───┼───┼──────┼──────┼─────┤                       ├───┼───┼───┼───┼───┼──────┤
//    │ tab  │ q │ w │  e   │  r   │  t  │                       │ y │ u │ i │ o │ p │  \   │
//    ├──────┼───┼───┼──────┼──────┼─────┤                       ├───┼───┼───┼───┼───┼──────┤
//    │ lctl │ a │ s │  d   │  f   │  g  │                       │ h │ j │ k │ l │ ; │  '   │
//    ├──────┼───┼───┼──────┼──────┼─────┼─────────┐   ┌─────────┼───┼───┼───┼───┼───┼──────┤
//    │ lsft │ z │ x │  c   │  v   │  b  │ kB_MUTE │   │         │ n │ m │ , │ . │ / │ rsft │
//    └──────┴───┼───┼──────┼──────┼─────┼─────────┤   ├─────────┼───┼───┼───┼───┼───┴──────┘
//               │ ` │ lalt │ lgui │ spc │ MO(_L1) │   │ MO(_L2) │ [ │ ] │ - │ = │
//               └───┴──────┴──────┴─────┴─────────┘   └─────────┴───┴───┴───┴───┘
[_BASE] = LAYOUT(
  KC_ESC  , KC_1 , KC_2   , KC_3    , KC_4    , KC_5   ,                            KC_6    , KC_7    , KC_8    , KC_9   , KC_0    , KC_BSPC     ,
  KC_TAB  , KC_Q , KC_W   , KC_E    , KC_R    , KC_T   ,                            KC_Y    , KC_U    , KC_I    , KC_O   , KC_P    , KC_BACKSLASH,
  KC_LCTL , KC_A , KC_S   , KC_D    , KC_F    , KC_G   ,                            KC_H    , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT     ,
  KC_LSFT , KC_Z , KC_X   , KC_C    , KC_V    , KC_B   , KC_KB_MUTE ,     KC_NO   , KC_N    , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT     ,
                   KC_GRV , KC_LALT , KC_LGUI , KC_SPC , MO(_L1)    ,     MO(_L2) , KC_LBRC , KC_RBRC , KC_MINS , KC_EQL
),

//    ┌───┬────┬────┬────┬────┬────┐                    ┌─────────┬────┬────┬────┬─────┬─────┐
//    │ ` │ f1 │ f2 │ f3 │ f4 │ f5 │                    │   f6    │ f7 │ f8 │ f9 │ f10 │ f11 │
//    ├───┼────┼────┼────┼────┼────┤                    ├─────────┼────┼────┼────┼─────┼─────┤
//    │ ▽ │ 1  │ 2  │ 3  │ 4  │ 5  │                    │    6    │ 7  │ 8  │ 9  │  0  │ f12 │
//    ├───┼────┼────┼────┼────┼────┤                    ├─────────┼────┼────┼────┼─────┼─────┤
//    │ ▽ │ !  │ @  │ #  │ $  │ %  │                    │    ^    │ &  │ *  │ (  │  )  │  |  │
//    ├───┼────┼────┼────┼────┼────┼───┐   ┌────────────┼─────────┼────┼────┼────┼─────┼─────┤
//    │ ▽ │ =  │ -  │ +  │ {  │ }  │ ▽ │   │     ▽      │    [    │ ]  │ ;  │ :  │  \  │ ent │
//    └───┴────┼────┼────┼────┼────┼───┤   ├────────────┼─────────┼────┼────┼────┼─────┴─────┘
//             │ ▽  │ ▽  │ ▽  │ ▽  │ ▽ │   │ www_search │ MO(_L3) │ ▽  │ ▽  │ ▽  │
//             └────┴────┴────┴────┴───┘   └────────────┴─────────┴────┴────┴────┘
[_L1] = LAYOUT(
  KC_GRV  , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                         KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
  KC_TRNS , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_F12  ,
  KC_TRNS , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC ,                         KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_PIPE ,
  KC_TRNS , KC_EQL  , KC_MINS , KC_PLUS , KC_LCBR , KC_RCBR , KC_TRNS ,     KC_TRNS , KC_LBRC , KC_RBRC , KC_SCLN , KC_COLN , KC_BSLS , KC_ENTER,
                      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_WSCH , MO(_L3) , KC_TRNS , KC_TRNS , KC_TRNS
),

//    ┌───┬─────────┬─────────┬─────────┬─────────┬──────┐           ┌──────┬────────────┬──────┬────────────┬────────────┬─────┐
//    │ ▽ │    ▽    │    ▽    │    ▽    │    ▽    │  ▽   │           │  ▽   │     ▽      │  ▽   │     ▽      │     ▽      │ del │
//    ├───┼─────────┼─────────┼─────────┼─────────┼──────┤           ├──────┼────────────┼──────┼────────────┼────────────┼─────┤
//    │ ▽ │   ins   │  pscr   │   app   │         │      │           │ pgup │ LCTL(left) │  up  │ LCTL(rght) │ LCTL(bspc) │     │
//    ├───┼─────────┼─────────┼─────────┼─────────┼──────┤           ├──────┼────────────┼──────┼────────────┼────────────┼─────┤
//    │ ▽ │  lalt   │  lctl   │  lsft   │         │ caps │           │ pgdn │    left    │ down │    rght    │            │ ent │
//    ├───┼─────────┼─────────┼─────────┼─────────┼──────┼───┐   ┌───┼──────┼────────────┼──────┼────────────┼────────────┼─────┤
//    │ ▽ │ LCTL(z) │ LCTL(x) │ LCTL(c) │ LCTL(v) │      │ ▽ │   │ ▽ │      │    home    │      │    end     │            │ ent │
//    └───┴─────────┼─────────┼─────────┼─────────┼──────┼───┤   ├───┼──────┼────────────┼──────┼────────────┼────────────┴─────┘
//                  │    ▽    │    ▽    │    ▽    │      │ ▽ │   │ ▽ │  ▽   │     ▽      │  ▽   │     ▽      │
//                  └─────────┴─────────┴─────────┴──────┴───┘   └───┴──────┴────────────┴──────┴────────────┘
[_L2] = LAYOUT(
  KC_TRNS , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS ,                         KC_TRNS , KC_TRNS       , KC_TRNS , KC_TRNS       , KC_TRNS       , KC_DEL  ,
  KC_TRNS , KC_INS     , KC_PSCR    , KC_APP     , KC_NO      , KC_NO   ,                         KC_PGUP , LCTL(KC_LEFT) , KC_UP   , LCTL(KC_RGHT) , LCTL(KC_BSPC) , KC_NO   ,
  KC_TRNS , KC_LALT    , KC_LCTL    , KC_LSFT    , KC_NO      , KC_CAPS ,                         KC_PGDN , KC_LEFT       , KC_DOWN , KC_RGHT       , KC_NO         , KC_ENTER,
  KC_TRNS , LCTL(KC_Z) , LCTL(KC_X) , LCTL(KC_C) , LCTL(KC_V) , KC_NO   , KC_TRNS ,     KC_TRNS , KC_NO   , KC_HOME       , KC_NO   , KC_END        , KC_NO         , KC_ENTER,
                         KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_NO   , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS       , KC_TRNS , KC_TRNS
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
[_L3] = LAYOUT(
  KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                         KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO,
  QK_BOOT , KC_NO , DF(0)   , KC_NO   , KC_NO   , KC_NO   ,                         KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO , KC_NO,
  KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                         KC_NO   , KC_VOLD , KC_MUTE , KC_VOLU , KC_NO , KC_NO,
  KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,     KC_NO   , KC_NO   , KC_MPRV , KC_MPLY , KC_MNXT , KC_NO , KC_NO,
                    KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS
)
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }
    }
    return false;
}
#endif
// clang-format on
