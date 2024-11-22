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
  370,
  392,
  440,
  494,
  523,
  587,
  659,
  698,
  740,
  784,
  800,
  988,
  1047,
  1109,
  1175,
  1245,
  1319,
  1397,
  1480,
  1568,
  1661,
  1760,
  1865,
  1976
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

void zeldas_lullaby() { // Zelda's Lullaby
  const uint8_t notes[] = {NOTE_C3, NOTE_G3, NOTE_E4, NOTE_C3, NOTE_A3, NOTE_Fsharp4,
			   NOTE_C3, NOTE_G3, NOTE_E4, NOTE_C3, NOTE_A3, NOTE_Fsharp4,
			   NOTE_C3, NOTE_B4, NOTE_G3, NOTE_E4, NOTE_D5, NOTE_C3,
			   NOTE_B4
                          };
  const uint8_t tempo[] = {5, 5, 5, 5, 5, 5,
			   5, 5, 5, 5, 5, 5,
			   7, 3, 5, 5, 5, 7,
			   3
                          };
  int noteAmt = sizeof(notes) / sizeof(notes[0]);
  playTune(notes, tempo, noteAmt);
  buzzer_set_period(0);
}
void oot() { // Ocarina of Time Theme
  const uint8_t notes[] = {NOTE_F2, NOTE_F3, NOTE_A3, NOTE_D4, NOTE_E4, NOTE_C2,
                           NOTE_G3, NOTE_B3, NOTE_D4, NOTE_E4, NOTE_F2, NOTE_C3,
                           NOTE_F3, NOTE_A3, NOTE_D4, NOTE_E4, NOTE_C2, NOTE_G2,
                           NOTE_E3, NOTE_B3, NOTE_D4, NOTE_E4, NOTE_D5, NOTE_D6,
			   NOTE_F2, NOTE_C3, NOTE_F3, NOTE_A3, NOTE_D4};
  const uint8_t tempo[] = {13, 3, 3, 3, 13, 13,
			   3, 3, 3, 13, 13, 6,
                           5, 5, 5, 13, 6, 5,
                           5, 5, 4, 5, 5, 13,
                           6, 3, 3, 3, 3, 6,
                           13, 3, 3};
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

void tp() { // Twilight Princess Theme
  const uint8_t notes[] = {NOTE_D3, NOTE_E3, NOTE_F3, NOTE_A3, NOTE_C4, NOTE_E4,
			   NOTE_D3, NOTE_E3, NOTE_F3, NOTE_A3, NOTE_C4, NOTE_E4,
			   NOTE_D3, NOTE_E3, NOTE_F3, NOTE_A3, NOTE_C4, NOTE_E4,
			   NOTE_G4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_E3,
			   NOTE_A4, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4,
			   NOTE_G4
                          };
  const uint8_t tempo[] = {4, 4, 4, 4, 4, 4,
			   4, 4, 4, 4, 4, 4,
			   3, 3, 3, 3, 3, 3,
			   3, 3, 3, 3, 3, 3,
			   5, 4, 4, 4, 4, 4,
                          };
  int noteAmt = sizeof(notes) / sizeof(notes[0]);
  playTune(notes, tempo, noteAmt);
  buzzer_set_period(0);
}
