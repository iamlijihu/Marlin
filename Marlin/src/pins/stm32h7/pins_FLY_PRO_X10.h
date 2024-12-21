/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2024 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define ALLOW_STM32DUINO
#include "env_validate.h"

#define BOARD_INFO_NAME      "FLY_PRO_X10"
#define DEFAULT_MACHINE_NAME BOARD_INFO_NAME

// Avoid conflict with fans and TIMER_TONE
#define TEMP_TIMER  3
#define STEP_TIMER  5

//
// EEPROM Emulation
//
#if NO_EEPROM_SELECTED
  #define FLASH_EEPROM_EMULATION
  //#define SRAM_EEPROM_EMULATION
  //#define I2C_EEPROM
#endif

#if ENABLED(FLASH_EEPROM_EMULATION)
  // Decrease delays and flash wear by spreading writes across
  // the 128kB sector allocated for EEPROM emulation.
  #define FLASH_EEPROM_LEVELING
#elif ENABLED(I2C_EEPROM)
  #define MARLIN_EEPROM_SIZE              0x2000  // 8K
#endif

#ifndef MARLIN_EEPROM_SIZE
  #define MARLIN_EEPROM_SIZE              0x1000  // 4K
#endif

//
// Servos
//
#define SERVO0_PIN                          PC6

//
// Limit Switches
//
#define X_MIN_PIN                           PG8
#define X_MAX_PIN                           PG7
#define Y_MIN_PIN                           PG6
#define Y_MAX_PIN                           PG5
#define Z_MIN_PIN                           PG4
#define Z_MAX_PIN                           PG3

#define IO6                                 PG2
#define IN                                  PF9
#define HVIN                                PB1

//
// Z Probe (when not Z_MIN_PIN)
//
#define Z_MIN_PROBE_PIN                     PC3  // Z3_PIN

//
// Steppers
//

#define X_STEP_PIN                          PE7
#define X_DIR_PIN                           PG11
#define X_ENABLE_PIN                        PG10
#ifndef X_CS_PIN
  #define X_CS_PIN                          PG12
#endif

#define Y_STEP_PIN                          PE8
#define Y_DIR_PIN                           PE14
#define Y_ENABLE_PIN                        PE13
#ifndef Y_CS_PIN
  #define Y_CS_PIN                          PE15
#endif

#define Z_STEP_PIN                          PE9
#define Z_DIR_PIN                           PG1
#define Z_ENABLE_PIN                        PG0
#ifndef Z_CS_PIN
  #define Z_CS_PIN                          PE12
#endif

#define E0_STEP_PIN                         PE10
#define E0_DIR_PIN                          PF14
#define E0_ENABLE_PIN                       PF13
#ifndef E0_CS_PIN
  #define E0_CS_PIN                         PF15
#endif

#define E1_STEP_PIN                         PE11
#define E1_DIR_PIN                          PF11
#define E1_ENABLE_PIN                       PB2
#ifndef E1_CS_PIN
  #define E1_CS_PIN                         PF12
#endif

#define E2_STEP_PIN                         PE2
#define E2_DIR_PIN                          PF10
#define E2_ENABLE_PIN                       PC0
#ifndef E2_CS_PIN
  #define E2_CS_PIN                         PF5
#endif

#define E3_STEP_PIN                         PE3
#define E3_DIR_PIN                          PF2
#define E3_ENABLE_PIN                       PF4
#ifndef E3_CS_PIN
  #define E3_CS_PIN                         PF1
#endif

#define E4_STEP_PIN                         PE4
#define E4_DIR_PIN                          PC15
#define E4_ENABLE_PIN                       PF0
#ifndef E4_CS_PIN
  #define E4_CS_PIN                         PC14
#endif

#define E5_STEP_PIN                         PE1
#define E5_DIR_PIN                          PB7
#define E5_ENABLE_PIN                       PC13
#ifndef E5_CS_PIN
  #define E5_CS_PIN                         PB6
#endif

#define E6_STEP_PIN                         PE0
#define E6_DIR_PIN                          PG14
#define E6_ENABLE_PIN                       PG15
#ifndef E6_CS_PIN
  #define E6_CS_PIN                         PG13
#endif


//
// Temperature Sensors
//
#define TEMP_0_PIN                          PC5   // Analog Input
#define TEMP_1_PIN                          PC4   // Analog Input
#define TEMP_2_PIN                          PA4   // Analog Input
#define TEMP_3_PIN                          PB0   // Analog Input
#define TEMP_4_PIN                          PC1   // Analog Input
#define TEMP_BED_PIN                        PF3   // Analog Input

//
// Heaters / Fans
//
#define HEATER_0_PIN                        PF8
#define HEATER_1_PIN                        PF7
#define HEATER_2_PIN                        PF6
#define HEATER_3_PIN                        PE6
#define HEATER_4_PIN                        PE5
#define HEATER_BED_PIN                      PC7

#ifndef FAN0_PIN
  #define FAN0_PIN                          PA0
#endif
#define FAN1_PIN                            PA1
#define FAN2_PIN                            PA2
#define FAN3_PIN                            PA3
#define FAN4_PIN                            PA15
#define FAN5_PIN                            PB10
#define FAN6_PIN                            PB11
#define FAN7_PIN                            PD12
#define FAN8_PIN                            PD14
#define FAN9_PIN                            PD15

//
// Onboard SD support
//
#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION              ONBOARD
#endif

#if SD_CONNECTION_IS(ONBOARD)

  #define ONBOARD_SDIO                            // Use SDIO for onboard SD

#endif

//
// Trinamic SPI
//
#ifndef TMC_SPI_SCK
  #define TMC_SPI_SCK                       PA5
#endif
#ifndef TMC_SPI_MISO
  #define TMC_SPI_MISO                      PA6
#endif
#ifndef TMC_SPI_MOSI
  #define TMC_SPI_MOSI                      PA7
#endif

//
// Trinamic Software Serial
//

#if HAS_TMC_UART
  #define X_SERIAL_TX_PIN                   PG12
  #define Y_SERIAL_TX_PIN                   PE15
  #define Z_SERIAL_TX_PIN                   PE12
  #define E0_SERIAL_TX_PIN                  PF15
  #define E1_SERIAL_TX_PIN                  PF12
  #define E2_SERIAL_TX_PIN                  PF5
  #define E3_SERIAL_TX_PIN                  PF1
  #define E4_SERIAL_TX_PIN                  PC14
  #define E5_SERIAL_TX_PIN                  PB6
  #define E6_SERIAL_TX_PIN                  PG13
#endif


