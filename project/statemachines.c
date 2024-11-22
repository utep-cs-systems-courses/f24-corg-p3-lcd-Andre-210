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
    // clearScreen(COLOR_RED);
    drawFurEliseImage();
    zeldas_lullaby();
    //main();
    //buzzer_set_period(1000);
    leds_off();
    break;
  case 2:
    led_flash(3);
    leds_off();
    red_led_on();
    //clearScreen(COLOR_ORANGE);
    drawHappyBdayImage();
    oot();
    //buzzer_set_period(1000);
    leds_off();
    break;
  case 3:
    led_flash(3);
    leds_off();
    red_led_on();
    //clearScreen(COLOR_BROWN);
    drawMarioImage();
    soh();
    //buzzer_set_period(1000);
    leds_off();
    break;
  case 4:
    led_flash(3);
    leds_off();
    red_led_on();
    //clearScreen(COLOR_GREEN);
    drawRunaweyImage();
    tp();
    //buzzer_set_period(1000);
    leds_off();
    break;
  default:
    green_led_on();
    break;
  }
  // turn on the green led to indicate that the MSP ready for the next step.
  green_led_on();
  //lcd_init();
  clearScreen(COLOR_BLUE);
}
