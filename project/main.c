#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

#include "lcdutils.h"
#include "lcddraw.h"

int main(void) {
  
  // ADDED
  P1DIR |= LED;		/**< Green led on when CPU on */
  P1OUT |= LED;
  //
  configureClocks();
  // ADDED
  lcd_init();
  //
  switch_init();              // initialize switches
  led_init();                 // initialize led
  buzzer_init();            // initialize buzzer

  green_led_on();             // turn on the green led
  enableWDTInterrupts();      // enable WatchDog interrupts

  // ADDED
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(BG_COLOR);
  while (1) {			/* forever */
    if (redrawScreen) {
      redrawScreen = 0;
      update_shape();
    }
    P1OUT &= ~LED;	/* led off */
    or_sr(0x10);	/**< CPU OFF */
    P1OUT |= LED;	/* led on */
  }
  //
}
