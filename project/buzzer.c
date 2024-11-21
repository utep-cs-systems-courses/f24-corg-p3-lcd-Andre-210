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
  buzzer_set_period(bk);
  
}

void fur_Elise()
{

  int notes[] = {E4, Dsharp4, E4, Dsharp4, E4, B3, D4, C4, A3, Asharp3, B3, D3, E3, Gsharp3, A3};
  int tempo[] = {362, 362, 362, 362, 362, 525, 543, 543, 700, 700, 543, 700, 543, 406, 700};

  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}

void happy_Bday()
{
  int notes[] = {F2, F3, A3, D4, E4, C2, G3, B3, D4, E4, F2, C3, F3, A3, D4, E4, C2, G2, E3, B3, D4, E4, D5, D6, F2, C3, F3, A3, D4, Csharp6, C6, E4, B5, C2, G2, E3, B3, A5, D4, G5, E4, D5, E5, D6, F2, C3, F3, A3, D4, Csharp6, C6, E6, B5, E6, C2, G2, E3, B3, D4, E4};
  int tempo[] ={1276, 300, 300, 300, 1276, 1276, 300, 300, 300, 1276, 1276, 600, 500, 500, 500, 1276, 600, 500, 500, 500, 400, 500, 500, 1276, 600, 300, 300, 300, 300, 600, 1276, 300, 300, 300, 300, 300, 300, 1276, 600, 300, 300, 500, 300, 500, 1276, 600, 300, 300, 300, 300, 300, 500, 400, 600, 1276, 600, 300, 300, 300, 300, 1276, 600, 300, 300, 300, 300, 300};
  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}

void Mario()
{
  int notes[] = {D4, G4, B4, A4, G4, Fsharp4, G4, A4, B4, A4, G4, Fsharp4, E4, Fsharp4, G4, D4, G4, B4, A4, G4, Fsharp4, G4, E4};
  int tempo[] = {500, 500, 500, 750, 250, 500, 500, 500, 750, 250, 500, 500, 750, 250, 500, 500, 500, 500, 750, 250, 500, 500, 1000};
  
  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}

void runawey()
{
  int notes[] = {A4, E5, Fsharp5, E5, A4, A4, E5, Fsharp5, E5, G4, A4, B4, C5, B4, A4, Fsharp4, G4, A4, B4, C5, E5, D5, C5, B4, A4};
  int tempo[] = {500, 500, 500, 500, 750, 500, 500, 500, 500, 750, 500, 500, 500, 500, 750, 500, 500, 500, 500, 750, 500, 500, 500, 500, 1000};

  int noteAmt = sizeof(notes)/sizeof(notes[0]);
  playTune(notes,tempo,noteAmt);
  buzzer_set_period(bk);
}
