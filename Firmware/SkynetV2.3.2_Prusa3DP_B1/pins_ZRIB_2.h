/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#if HOTENDS > 2
  #error "Zrib v2 supports up to 2 hotends. Comment this line to keep going."
#endif

#define BOARD_NAME "ZRIB v2.x"

#include "pins_RAMPS.h"

#undef FAN_PIN 
#define FAN_PIN 9 

#if HOTENDS == 2
  #undef HEATER_1_PIN
  #define HEATER_1_PIN 7
#endif

//switch Z_MIN_ZMAX and Z_MAX_PIN for auto bed leveling
#ifdef Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
  #undef Z_MIN_PIN  
  #define Z_MIN_PIN 19
#endif

#ifdef FILAMENT_RUNOUT_SENSOR
  #undef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN 15 //Y_MAX_PIN
#endif

//Definition for Zonestar keypad LCD
//#if ENABLED(ULTRA_LCD) && ENABLED(NEWPANEL) //*?? nebo 
#if ENABLED(ZONESTAR_KEYPAD_LCD)
  #undef LCD_PINS_RS
  #undef LCD_PINS_ENABLE
  #undef LCD_PINS_D4
  #undef LCD_PINS_D5
  #undef LCD_PINS_D6
  #undef LCD_PINS_D7
  #undef BTN_EN1
  #undef BTN_EN2
  #undef BTN_ENC
  #undef BEEPER_PIN
  #undef SD_DETECT_PIN
  #undef KILL_PIN

  #define LCD_PINS_RS 16
  #define LCD_PINS_ENABLE 17
  #define LCD_PINS_D4 23
  #define LCD_PINS_D5 25
  #define LCD_PINS_D6 27
  #define LCD_PINS_D7 29
  #define ADC_KEYPAD_PIN 10
  #define BEEPER_PIN 37 
  #define SD_DETECT_PIN 49
  #define KILL_PIN 41
    
  #define BTN_EN1         -1
  #define BTN_EN2         -1
  #define BTN_ENC         -1

  #define ENCODER_FEEDRATE_DEADZONE 2 //original value 2

#endif


 
