#include "keycodes.h"
#include "keymap_us.h"
#include "process_tap_dance.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

enum sofle_layers {
    _BASE,
    _L1,
    _L2,
    _L3,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────────────────┬───┬────────────┬──────┬──────┬─────┐                             ┌─────┬───┬───────────────┬─────┬───┬──────┐
//    │        esc        │ 1 │     2      │  3   │  4   │  5  │                             │  6  │ 7 │       8       │  9  │ 0 │ bspc │
//    ├───────────────────┼───┼────────────┼──────┼──────┼─────┤                             ├─────┼───┼───────────────┼─────┼───┼──────┤
//    │        tab        │ q │     w      │  e   │  r   │  t  │                             │  y  │ u │       i       │  o  │ p │  \   │
//    ├───────────────────┼───┼────────────┼──────┼──────┼─────┤                             ├─────┼───┼───────────────┼─────┼───┼──────┤
//    │       lctl        │ a │     s      │  d   │  f   │  g  │                             │  h  │ j │       k       │  l  │ ; │  '   │
//    ├───────────────────┼───┼────────────┼──────┼──────┼─────┼────────────┐   ┌────────────┼─────┼───┼───────────────┼─────┼───┼──────┤
//    │ LSFT_T(caps_LOCK) │ z │     x      │  c   │  v   │  b  │  kB_MUTE   │   │            │  n  │ m │       ,       │  .  │ / │ rsft │
//    └───────────────────┴───┼────────────┼──────┼──────┼─────┼────────────┤   ├────────────┼─────┼───┼───────────────┼─────┼───┴──────┘
//                            │ LT(_L3, `) │ lalt │ lgui │ spc │ LT(_L1, [) │   │ LT(_L2, =) │ ent │ - │ QK_REPEAT_KEY │ del │
//                            └────────────┴──────┴──────┴─────┴────────────┘   └────────────┴─────┴───┴───────────────┴─────┘
[_BASE] = LAYOUT(
  KC_ESC               , KC_1 , KC_2              , KC_3    , KC_4    , KC_5     ,                                          KC_6     , KC_7    , KC_8          , KC_9   , KC_0    , KC_BSPC     ,
  KC_TAB               , KC_Q , KC_W              , KC_E    , KC_R    , KC_T     ,                                          KC_Y     , KC_U    , KC_I          , KC_O   , KC_P    , KC_BACKSLASH,
  KC_LCTL              , KC_A , KC_S              , KC_D    , KC_F    , KC_G     ,                                          KC_H     , KC_J    , KC_K          , KC_L   , KC_SCLN , KC_QUOT     ,
  LSFT_T(KC_CAPS_LOCK) , KC_Z , KC_X              , KC_C    , KC_V    , KC_B     , KC_KB_MUTE       ,     KC_NO           , KC_N     , KC_M    , KC_COMM       , KC_DOT , KC_SLSH , KC_RSFT     ,
                                LT(_L3, KC_GRAVE) , KC_LALT , KC_LGUI , KC_SPACE , LT(_L1, KC_LBRC) ,     LT(_L2, KC_EQL) , KC_ENTER , KC_MINS , QK_REPEAT_KEY , KC_DEL
),

//    ┌───┬───┬───┬───┬────────────┬───┐           ┌───┬──────┬──────┬──────┬───┬─────┐
//    │ ` │   │   │   │            │   │           │   │      │      │      │   │ del │
//    ├───┼───┼───┼───┼────────────┼───┤           ├───┼──────┼──────┼──────┼───┼─────┤
//    │   │   │   │   │            │   │           │   │ vold │ mute │ volu │   │     │
//    ├───┼───┼───┼───┼────────────┼───┤           ├───┼──────┼──────┼──────┼───┼─────┤
//    │   │   │   │   │ www_search │   │           │   │ mnxt │ mply │ mprv │   │     │
//    ├───┼───┼───┼───┼────────────┼───┼───┐   ┌───┼───┼──────┼──────┼──────┼───┼─────┤
//    │   │   │   │   │            │   │   │   │   │   │      │      │      │   │     │
//    └───┴───┼───┼───┼────────────┼───┼───┤   ├───┼───┼──────┼──────┼──────┼───┴─────┘
//            │   │   │            │   │   │   │   │   │      │      │      │
//            └───┴───┴────────────┴───┴───┘   └───┴───┴──────┴──────┴──────┘
[_L1] = LAYOUT(
  KC_GRAVE , KC_NO , KC_NO , KC_NO , KC_NO         , KC_NO ,                     KC_NO , KC_NO               , KC_NO               , KC_NO               , KC_NO , KC_DEL,
  KC_NO    , KC_NO , KC_NO , KC_NO , KC_NO         , KC_NO ,                     KC_NO , KC_VOLD             , KC_MUTE             , KC_VOLU             , KC_NO , KC_NO ,
  KC_NO    , KC_NO , KC_NO , KC_NO , KC_WWW_SEARCH , KC_NO ,                     KC_NO , KC_MEDIA_NEXT_TRACK , KC_MEDIA_PLAY_PAUSE , KC_MEDIA_PREV_TRACK , KC_NO , KC_NO ,
  KC_NO    , KC_NO , KC_NO , KC_NO , KC_NO         , KC_NO , KC_NO ,     KC_NO , KC_NO , KC_NO               , KC_NO               , KC_NO               , KC_NO , KC_NO ,
                     KC_NO , KC_NO , KC_NO         , KC_NO , KC_NO ,     KC_NO , KC_NO , KC_NO               , KC_NO               , KC_NO
),

//    ┌────┬────┬─────────┬─────────┬─────────┬────┐           ┌────────────┬────────────┬──────────┬────────────┬─────┬─────┐
//    │ f1 │ f2 │   f3    │   f4    │   f5    │ f6 │           │     f7     │     f8     │    f9    │    f10     │ f11 │ f12 │
//    ├────┼────┼─────────┼─────────┼─────────┼────┤           ├────────────┼────────────┼──────────┼────────────┼─────┼─────┤
//    │    │    │         │         │         │    │           │ LCTL(left) │ LCTL(down) │ LCTL(up) │ LCTL(rght) │     │     │
//    ├────┼────┼─────────┼─────────┼─────────┼────┤           ├────────────┼────────────┼──────────┼────────────┼─────┼─────┤
//    │    │    │         │         │         │    │           │    left    │    down    │    up    │    rght    │     │     │
//    ├────┼────┼─────────┼─────────┼─────────┼────┼───┐   ┌───┼────────────┼────────────┼──────────┼────────────┼─────┼─────┤
//    │    │    │ LCTL(x) │ LCTL(c) │ LCTL(v) │    │   │   │   │    home    │    pgdn    │   pgup   │    end     │     │ ent │
//    └────┴────┼─────────┼─────────┼─────────┼────┼───┤   ├───┼────────────┼────────────┼──────────┼────────────┼─────┴─────┘
//              │         │         │         │    │ ] │   │   │            │            │          │            │
//              └─────────┴─────────┴─────────┴────┴───┘   └───┴────────────┴────────────┴──────────┴────────────┘
[_L2] = LAYOUT(
  KC_F1 , KC_F2 , KC_F3      , KC_F4      , KC_F5      , KC_F6 ,                       KC_F7         , KC_F8         , KC_F9       , KC_F10         , KC_F11 , KC_F12  ,
  KC_NO , KC_NO , KC_NO      , KC_NO      , KC_NO      , KC_NO ,                       LCTL(KC_LEFT) , LCTL(KC_DOWN) , LCTL(KC_UP) , LCTL(KC_RIGHT) , KC_NO  , KC_NO   ,
  KC_NO , KC_NO , KC_NO      , KC_NO      , KC_NO      , KC_NO ,                       KC_LEFT       , KC_DOWN       , KC_UP       , KC_RIGHT       , KC_NO  , KC_NO   ,
  KC_NO , KC_NO , LCTL(KC_X) , LCTL(KC_C) , LCTL(KC_V) , KC_NO , KC_NO   ,     KC_NO , KC_HOME       , KC_PGDN       , KC_PGUP     , KC_END         , KC_NO  , KC_ENTER,
                  KC_NO      , KC_NO      , KC_NO      , KC_NO , KC_RBRC ,     KC_NO , KC_NO         , KC_NO         , KC_NO       , KC_NO
),

//    ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
//    │   │   │   │   │   │   │           │   │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
//    │   │   │   │   │   │   │           │   │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
//    │   │   │   │   │   │   │           │   │   │   │   │   │   │
//    ├───┼───┼───┼───┼───┼───┼───┐   ┌───┼───┼───┼───┼───┼───┼───┤
//    │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
//    └───┴───┼───┼───┼───┼───┼───┤   ├───┼───┼───┼───┼───┼───┴───┘
//            │   │   │   │   │ ] │   │   │   │   │   │   │
//            └───┴───┴───┴───┴───┘   └───┴───┴───┴───┴───┘
[_L3] = LAYOUT(
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                       KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                       KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                       KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO   ,     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
                  KC_NO , KC_NO , KC_NO , KC_NO , KC_RBRC ,     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO
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

#ifdef OLED_ENABLE
static void render_logo_user(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a,
                                            0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0,
                                            0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab,
                                            0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1,
                                            0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc,
                                            0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};
    oled_write_P(qmk_logo, false);
}

void print_status_narrow_user(void) {
    oled_write_P(PSTR("\n\n"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR(" LY0 \n"), true);
            break;
        case _L1:
            oled_write_P(PSTR(" LY1 \n"), true);
            break;
        case _L2:
            oled_write_P(PSTR(" LY2 \n"), true);
            break;
        case _L3:
            oled_write_P(PSTR(" LY3 \n"), true);
            break;
        default:
            oled_write_ln_P(PSTR(" ??? \n"), true);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write_P(PSTR("CPSLK\n"), false);
    } else {
        oled_write_P(PSTR("     \n"), false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow_user();
    } else {
        render_logo_user();
        oled_scroll_left();
    }
    return false;
}

#endif
