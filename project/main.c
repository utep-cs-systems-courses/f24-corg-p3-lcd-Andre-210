#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "song_images.h"

int main(void) {
  configureClocks();
  lcd_init();                 // initialize lcd screen
  switch_init();              // initialize switches
  led_init();                 // initialize led
  buzzer_init();              // initialize buzzer
  green_led_on();             // turn on the green led
  enableWDTInterrupts();      // enable WatchDog interrupts
  or_sr(0x18);                // CPU off, GIE on
}
