 /* Copyright 2020 Bratzworth 
  * 
  * This program is free software: you can redistribute it and/or modify 
  * it under the terms of the GNU General Public License as published by 
  * the Free Software Foundation, either version 2 of the License, or 
  * (at your option) any later version. 
  * 
  * This program is distributed in the hope that it will be useful, 
  * but WITHOUT ANY WARRANTY; without even the implied warranty of 
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
  * GNU General Public License for more details. 
  * 
  * You should have received a copy of the GNU General Public License 
  * along with this program.  If not, see <http://www.gnu.org/licenses/>. 
  */
#include QMK_KEYBOARD_H

#define _MAIN 0
#define _FN 1


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = LAYOUT(
    KC_HOME, KC_5,  KC_INSERT,  
    KC_SPACE, MT(KC_9, KC_8)
  ),

  [_FN] = LAYOUT(
    KC_F13, KC_F14, KC_F15,
    KC_F16, KC_F17
  )
};

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            if (active) {
                set_single_persistent_default_layer(_FN);
            } else {
                set_single_persistent_default_layer(_MAIN);
            }
        }
    }
}