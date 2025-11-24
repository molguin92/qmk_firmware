// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later
// clang-format off

#pragma once

#define TAPPING_TERM 150 // the default of 200ms seems sluggish

#ifdef RGB_MATRIX_ENABLE
// turn off effects when suspended
#define RGB_MATRIX_SLEEP
#define RGB_MATRIX_TIMEOUT 90000 // 90s
// limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150

#define ENABLE_RGB_MATRIX_RIVERFLOW
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RIVERFLOW
#define RGB_MATRIX_DEFAULT_ON true
#define RGB_MATRIX_DEFAULT_HUE 201
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_DEFAULT_SPD 150
#define RGBLIGHT_DISABLE_KEYCODES

#endif
