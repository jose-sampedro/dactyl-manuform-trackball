#pragma once

#include "config_common.h"

#define PRODUCT_ID                  0x3536
#define DEVICE_VER                  0x0001

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS                 12
#define MATRIX_COLS                 6

#define DIODE_DIRECTION             COL2ROW

#define ROTATIONAL_TRANSFORM_ANGLE  -25
#define POINTING_DEVICE_INVERT_X

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW          0
#define BOOTMAGIC_LITE_COLUMN       0
#define BOOTMAGIC_LITE_ROW_RIGHT    6
#define BOOTMAGIC_LITE_COLUMN_RIGHT 5

#define DYNAMIC_KEYMAP_LAYER_COUNT  16
#define LAYER_STATE_16BIT

#define POINTING_DEVICE_RIGHT
