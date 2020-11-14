/*
 * buttons_config.h
 *
 * Copyright (c) 2020, Erich Styger
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef BUTTONS_CONFIG_H_
#define BUTTONS_CONFIG_H_

#include "McuLib.h"

/* button pins are defined in IncludeMcuLibConfig.h */
#if McuLib_CONFIG_CPU_IS_KINETIS
#if TINYK22_HAT_VERSION==3
  #define BUTTONS_PINS_HATNAVUP_GPIO      PINS_HATNAVRIGHT_GPIO
  #define BUTTONS_PINS_HATNAVUP_PORT      PINS_HATNAVRIGHT_PORT
  #define BUTTONS_PINS_HATNAVUP_PIN       PINS_HATNAVRIGHT_PIN

  #define BUTTONS_PINS_HATNAVDOWN_GPIO    PINS_HATNAVLEFT_GPIO
  #define BUTTONS_PINS_HATNAVDOWN_PORT    PINS_HATNAVLEFT_PORT
  #define BUTTONS_PINS_HATNAVDOWN_PIN     PINS_HATNAVLEFT_PIN

  #define BUTTONS_PINS_HATNAVLEFT_GPIO    PINS_HATNAVUP_GPIO
  #define BUTTONS_PINS_HATNAVLEFT_PORT    PINS_HATNAVUP_PORT
  #define BUTTONS_PINS_HATNAVLEFT_PIN     PINS_HATNAVUP_PIN

  #define BUTTONS_PINS_HATNAVRIGHT_GPIO   PINS_HATNAVDOWN_GPIO
  #define BUTTONS_PINS_HATNAVRIGHT_PORT   PINS_HATNAVDOWN_PORT
  #define BUTTONS_PINS_HATNAVRIGHT_PIN    PINS_HATNAVDOWN_PIN

  #define BUTTONS_PINS_HATNAVCENTER_GPIO  PINS_HATNAVPUSH_GPIO
  #define BUTTONS_PINS_HATNAVCENTER_PORT  PINS_HATNAVPUSH_PORT
  #define BUTTONS_PINS_HATNAVCENTER_PIN   PINS_HATNAVPUSH_PIN

  #define BUTTONS_ENABLE_CLOCK() CLOCK_EnableClock(kCLOCK_PortB) /* enable clocking */
#else
  #define BUTTONS_PINS_HATNAVUP_GPIO      PINS_HATNAVUP_GPIO
  #define BUTTONS_PINS_HATNAVUP_PORT      PINS_HATNAVUP_PORT
  #define BUTTONS_PINS_HATNAVUP_PIN       PINS_HATNAVUP_PIN

  #define BUTTONS_PINS_HATNAVDOWN_GPIO    PINS_HATNAVDOWN_GPIO
  #define BUTTONS_PINS_HATNAVDOWN_PORT    PINS_HATNAVDOWN_PORT
  #define BUTTONS_PINS_HATNAVDOWN_PIN     PINS_HATNAVDOWN_PIN

  #define BUTTONS_PINS_HATNAVLEFT_GPIO    PINS_HATNAVLEFT_GPIO
  #define BUTTONS_PINS_HATNAVLEFT_PORT    PINS_HATNAVLEFT_PORT
  #define BUTTONS_PINS_HATNAVLEFT_PIN     PINS_HATNAVLEFT_PIN

  #define BUTTONS_PINS_HATNAVRIGHT_GPIO   PINS_HATNAVRIGHT_GPIO
  #define BUTTONS_PINS_HATNAVRIGHT_PORT   PINS_HATNAVRIGHT_PORT
  #define BUTTONS_PINS_HATNAVRIGHT_PIN    PINS_HATNAVRIGHT_PIN

  #define BUTTONS_PINS_HATNAVCENTER_GPIO  PINS_HATNAVPUSH_GPIO
  #define BUTTONS_PINS_HATNAVCENTER_PORT  PINS_HATNAVPUSH_PORT
  #define BUTTONS_PINS_HATNAVCENTER_PIN   PINS_HATNAVPUSH_PIN

  #define BUTTONS_ENABLE_CLOCK() CLOCK_EnableClock(kCLOCK_PortA); CLOCK_EnableClock(kCLOCK_PortB) /* enable clocking */
#endif
#elif McuLib_CONFIG_CPU_IS_LPC
   /* user button on LPC845-BRK board: PIO0_4 */
  #define BUTTONS_USER_GPIO       GPIO
  #define BUTTONS_USER_PORT       0
  #define BUTTONS_USER_PIN        4
  #define BUTTONS_USER_IOCON      IOCON_INDEX_PIO0_4

  #define BUTTONS_ENABLE_CLOCK() GPIO_PortInit(GPIO, 0) /* ungate the clocks for GPIO0: used for user button */
#endif

typedef enum {
#if McuLib_CONFIG_CPU_IS_KINETIS
  BTN_NAV_UP,
  BTN_NAV_DOWN,
  BTN_NAV_LEFT,
  BTN_NAV_RIGHT,
  BTN_NAV_CENTER,
#elif McuLib_CONFIG_CPU_IS_LPC
  BTN_USER,
#endif
  BTN_NAV_NOF_BUTTONS  /* sentinel, must be last in list! */
} BTN_Buttons_e;

#endif /* BUTTONS_CONFIG_H_ */
