#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"
#include "notes.h"
#include "statemachines.h"
#include "led.h"

#include <stdint.h>

const int frequencies[] = {
  0,
  65,
  73,
  82,
  87,
  98,
  110,
  123,
  131,
  146,
  165,
  175,
  196,
  220,
  247,
  262,
  294,
  330,
  349,
  392,
  440,
  494,
  523,
  587,
  659,
  698,
  784,
  800,
  988
};
const int baseTempo = 100;

void buzzer_init() {
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) {
  CCR0 = cycles; 
  CCR1 = cycles >> 1;	
}

void playTune(const uint8_t *notes, const uint8_t *tempo, int noteAmt) {
  for(int i = 0; i < noteAmt; i++) {
    if((i % 2) == 0 ) {
      red_led_on();
    }
    else {
      green_led_on();
    }
    int frequency = frequencies[notes[i]];
    buzzer_set_period(frequency ? 1000000 / frequency : 0);
    int dur = tempo[i] * baseTempo;
    while(dur--) {
	__delay_cycles(10000);
    }
    leds_off();
  }
  // reset the buzzer state
  buzzer_set_period(0);                 // turn off buzzer CHANGED FROM bk TO 0
  leds_off();                           // endsure leds are off
}

//void zeldas_lullaby() { // Zelda's Lullaby
  // notes for song (store in flash)
  //const int notes[] = {C3, G3, E4, C3, A3, Fsharp4, C3, G3, E4, C3, A3, Fsharp4, C3, B4, G3};
  // tempo for each note (store in flash)
  //const int tempo[] = {500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 750, 250, 500};
  // play the song
  //int noteAmt = sizeof(notes)/sizeof(notes[0]);
  //playTune(notes,tempo,noteAmt);
  // reset the buzzer state
  //buzzer_set_period(0); // CHANGED FROM bk TO 0
//}

void oot() { // Ocarina of Time Theme
  const uint8_t notes[] = {NOTE_F2, NOTE_F3, NOTE_A3, NOTE_D4, NOTE_E4, NOTE_C2};
  const uint8_t tempo[] = {13, 3, 3, 3, 13, 13};
  int noteAmt = sizeof(notes) / sizeof(notes[0]);
  playTune(notes, tempo, noteAmt);
}

//void soh() { // Song of Healing
  // notes for song (store in flash)
  //const int notes[] = {F3, B4, C4, A4, C4, F4, C4, F3, B4, C4, A4, C4, F4, C4, F3, B4, C4, A4, E4, D4, C4, E4, E3, B3, F3, B4, C4, A4, C4, F4, C4, F3, B4, C4, A4, C4, F4, C4, F3, B4, C4};
  // tempo for each note (store in flash)
  //const int tempo[] = {800, 800, 600, 600, 600, 800, 600, 800, 800, 600, 600, 600, 800, 800, 800, 800, 600, 600, 600, 800, 800, 800, 900, 900, 900, 800, 800, 600, 600, 600, 800, 600, 800, 800, 600, 600, 600, 800, 600, 800, 800, 600}; 
  //const int notes[] = {F3, B4, C4, A4, C4, F4, C4, F3, B4, C4, A4, C4, F4, C4, F3, B4, C4, A4, E4, D4, C4, E4, E3};
//const int tempo[] = {800, 800, 600, 600, 600, 800, 600, 800, 800, 600, 600, 600, 800, 800, 800, 800, 600, 600, 600, 800, 800, 800, 900};
  // play the song
  //int noteAmt = sizeof(notes)/sizeof(notes[0]);
  //playTune(notes,tempo,noteAmt);
  // reset the buzzer state
  //buzzer_set_period(0); // CHANGED FROM bk TO 0
//}

//void tp() { // Twilight Princess Theme
  // notes for the song (store in flash)
  //const int notes[] = {D3, E3, F3, A3, C4, E4, D3, E3, F3, A3, C4, E4, D3, E3, F3, A3, C4, E4, G4, E4, C4, A3, F3, E3, A4, F5, E5, C5, B4, A4, G4, B4, D6, A6, E6, D6};
  // tempo for each note (store in flash)
  //const int tempo[] = {400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 500, 400, 400, 400, 400, 400, 400, 400, 300, 300, 300, 300};
  //const int notes[] = {D3, E3, F3, A3, C4, E4, D3, E3, F3, A3, C4, E4, D3, E3, F3, A3, C4, E4, G4, E4, C4, A3, F3, E3, A4, F5, E5, C5, B4, A4};
  //const int tempo[] = {400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 400, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 500, 400, 400, 400, 400, 400};
  // play the song
  //int noteAmt = sizeof(notes)/sizeof(notes[0]);
  //playTune(notes,tempo,noteAmt);
  // reset the buzzer state
  //buzzer_set_period(0); // CHANGED FROM bk TO 0
  //}
