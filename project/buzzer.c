#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"
#include "notes.h"
#include "statemachines.h"
#include "led.h"

void buzzer_init()
{
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;	
}

void playTune(int *notes, int*tempo, int noteAmt)
{
  for(int i = 0; i < noteAmt; i++)
  {
    if((i % 2) == 0 ){
      red_led_on();
    }else{
      green_led_on();
    }

    buzzer_set_period(1000000 / notes[i]);
    int dur = tempo[i];
    while(dur--)
    {
    __delay_cycles(10000);

    }
    leds_off();
  }
  buzzer_set_period(bk);             // turn off buzzer
  // P2SEL &= ~BIT6;                    // disable buzzer pin
  //P2DIR &= ~BIT6;                    // enable pin to input mode
  //__delay_cycles(100000);            // grace period
}

void zeldas_lullaby() // Zelda's Lullaby
{

  int notes[] = {C3, G3, E4, C3, A3, Fsharp4, C3, G3, E4, C3, A3, Fsharp4, C3, B4, G3};
  int tempo[] = {500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 750, 250, 500};

  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}

void oot() // Ocarina of Time Theme
{
  int notes[] = {F2, F3, A3, D4, E4, C2, G3, B3, D4, E4, F2, C3, F3, A3, D4, E4, C2, G2, E3, B3, D4, E4, D5, D6, F2, C3, F3, A3, D4, Csharp6, C6, E4, B5, C2, G2, E3, B3, A5, D4, G5, E4};
  int tempo[] ={1276, 300, 300, 300, 1276, 1276, 300, 300, 300, 1276, 1276, 600, 500, 500, 500, 1276, 600, 500, 500, 500, 400, 500, 500, 1276, 600, 300, 300, 300, 300, 600, 1276, 300, 300, 300, 300, 300, 300, 1276, 600, 300, 300, 500, 300, 500, 1276};
  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}

void soh() // Song of Healing
{
  int notes[] = {F3, B4, C4, A4, C4, F4, C4, F3, B4, C4, A4, C4, F4, C4, F3, B4, C4, A4, E4, D4, C4, E4, E3, B3, B3, B3, F3, B4, C4, A4, C4, F4, C4, F3, B4, C4, A4, C4, F4, C4, F3, B4, C4};
  int tempo[] = {500, 500, 400, 400, 400, 500, 400, 500, 500, 400, 400, 400, 500, 400, 500, 500, 400, 400, 400, 500, 500, 500, 600, 600, 600, 600, 600, 500, 500, 400, 400, 400, 500, 400, 500, 500, 400, 400, 400, 500, 400, 500, 500, 400}; 
  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}

void tp() // Twilight Princess Theme
{
  int notes[] = {D3, E3, F3, A3, C4, E4, D3, E3, F3, A3, C4, E4, D3, E3, F3, A3, C4, E4, G4, E4, C4, A3, F3, E3, A4, F5, E5, C5, B4, A4, G4, B4, D6, A6, E6, D6};
  int tempo[] = {        400, 400, 400, 400, 400, 400, 
			 400, 400, 400, 400, 400, 400,
			 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
			 500, 400, 400, 400, 400, 400, 400, 400,
			 300, 300, 300, 300};

  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}
