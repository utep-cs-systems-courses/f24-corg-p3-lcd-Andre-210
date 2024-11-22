#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"

#include "lcdutils.h"
#include "lcddraw.h"
#include "song_images.h"

void next_state(int state) {
  leds_off();
  
  switch(state) {
  case 1:
    led_flash(3);
    leds_off();
    red_led_on();
    //drawZeldasLullaby();
    drawHarp(screenWidth / 2, screenHeight / 3, 60, COLOR_BROWN, "Zelda's Lullaby");
    zeldas_lullaby();
    //oot(); // added
    //tp();
    leds_off();
    break;
  case 2:
    led_flash(3);
    leds_off();
    red_led_on();
    //drawOOT();
    //drawDefault(COLOR_TURQUOISE, "Ocarina of Time");
    drawHyruleShieldWithSword(64, 50, 40, COLOR_FOREST_GREEN, "Ocarina of Time"); // Draw the Hyrule Shield at center
    oot();
    //tp();
    leds_off();
    break;
  case 3:
    led_flash(3);
    leds_off();
    red_led_on();
    //drawSOH();
    drawHarp(screenWidth / 2, screenHeight / 3, 60, COLOR_PURPLE, "Majora's Mask");
    soh();
    //oot(); // added
    //tp();
    leds_off();
    break;
  case 4:
    led_flash(3);
    leds_off();
    red_led_on();
    //drawTP();
    drawHyruleShieldWithSword(64, 50, 40, COLOR_FOREST_GREEN, "Twilight Princess"); // Draw the Hyrule Shield at center
    tp();
    //oot(); // added
    leds_off();
    break;
  default:
    green_led_on();
    break;
  }
  // turn on the green led to indicate that the MSP ready for the next step.
  green_led_on();
  drawDefault(COLOR_BLACK, "Song Player");
}
