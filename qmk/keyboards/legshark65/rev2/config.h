// Copyright 2023 jemmec (@jemmec)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

#define LED_CAPS_LOCK_PIN B12

/* disable print */
#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

#define EEPROM_I2C_24LC256
