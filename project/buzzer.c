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
  // Patterns for unique segments
    const uint8_t pattern1_notes[] = {NOTE_C3, NOTE_G3, NOTE_E4, NOTE_C3, NOTE_A3, NOTE_Fsharp4};
    const uint8_t pattern2_notes[] = {NOTE_C3, NOTE_B4, NOTE_G3};

    const uint8_t pattern1_tempo[] = {5, 5, 5, 5, 5, 5};
    const uint8_t pattern2_tempo[] = {7, 3, 5};

    // Sequence of patterns to play
    const uint8_t sequence[] = {1, 1, 2};

    // Play each pattern in sequence
    for (int i = 0; i < sizeof(sequence) / sizeof(sequence[0]); i++) {
        switch (sequence[i]) {
            case 1:
                playTune(pattern1_notes, pattern1_tempo, sizeof(pattern1_notes) / sizeof(pattern1_notes[0]));
                break;
            case 2:
                playTune(pattern2_notes, pattern2_tempo, sizeof(pattern2_notes) / sizeof(pattern2_notes[0]));
                break;
        }
    }

    // Reset the buzzer state
    buzzer_set_period(0); // Turn off buzzer
}
void oot() { // Ocarina of Time Theme
  // Patterns for unique segments
    const uint8_t pattern1_notes[] = {NOTE_F2, NOTE_F3, NOTE_A3, NOTE_D4, NOTE_E4};
    const uint8_t pattern2_notes[] = {NOTE_C2, NOTE_G3, NOTE_B3, NOTE_D4, NOTE_E4};
    const uint8_t pattern3_notes[] = {NOTE_C3, NOTE_F3, NOTE_A3, NOTE_D4, NOTE_E4};
    const uint8_t pattern4_notes[] = {NOTE_G2, NOTE_E3, NOTE_B3, NOTE_D4, NOTE_E4};
    const uint8_t pattern5_notes[] = {NOTE_D5, NOTE_D6};

    const uint8_t pattern1_tempo[] = {13, 3, 3, 3, 13};
    const uint8_t pattern2_tempo[] = {13, 3, 3, 3, 13};
    const uint8_t pattern3_tempo[] = {6, 5, 5, 5, 13};
    const uint8_t pattern4_tempo[] = {6, 5, 5, 5, 4};
    const uint8_t pattern5_tempo[] = {5, 13};

    // Sequence of patterns to play
    const uint8_t sequence[] = {1, 2, 3, 1, 4, 5, 3, 1};

    // Play each pattern in sequence
    for (int i = 0; i < sizeof(sequence) / sizeof(sequence[0]); i++) {
        switch (sequence[i]) {
            case 1:
                playTune(pattern1_notes, pattern1_tempo, sizeof(pattern1_notes) / sizeof(pattern1_notes[0]));
                break;
            case 2:
                playTune(pattern2_notes, pattern2_tempo, sizeof(pattern2_notes) / sizeof(pattern2_notes[0]));
                break;
            case 3:
                playTune(pattern3_notes, pattern3_tempo, sizeof(pattern3_notes) / sizeof(pattern3_notes[0]));
                break;
            case 4:
                playTune(pattern4_notes, pattern4_tempo, sizeof(pattern4_notes) / sizeof(pattern4_notes[0]));
                break;
            case 5:
                playTune(pattern5_notes, pattern5_tempo, sizeof(pattern5_notes) / sizeof(pattern5_notes[0]));
                break;
        }
    }

    // Reset the buzzer state
    buzzer_set_period(0); // Turn off buzzer
}

void soh() { // Song of Healing
    // Patterns for unique segments
    const uint8_t pattern1_notes[] = {NOTE_F3, NOTE_B4, NOTE_C4, NOTE_A4, NOTE_C4, NOTE_F4, NOTE_C4};
    const uint8_t pattern2_notes[] = {NOTE_F3, NOTE_B4, NOTE_C4, NOTE_A4, NOTE_C4, NOTE_F4, NOTE_C4};
    const uint8_t pattern3_notes[] = {NOTE_F3, NOTE_B4, NOTE_C4, NOTE_A4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_E4};
    const uint8_t pattern4_notes[] = {NOTE_E3, NOTE_B3};

    const uint8_t pattern1_tempo[] = {8, 8, 6, 6, 6, 8, 6};
    const uint8_t pattern2_tempo[] = {8, 8, 6, 6, 6, 8, 8};
    const uint8_t pattern3_tempo[] = {8, 8, 6, 6, 6, 8, 8, 9};
    const uint8_t pattern4_tempo[] = {9, 9};

    // Sequence of patterns to play
    const uint8_t sequence[] = {1, 2, 1, 3, 4};

    // Play each pattern in sequence
    for (int i = 0; i < sizeof(sequence) / sizeof(sequence[0]); i++) {
        switch (sequence[i]) {
            case 1:
                playTune(pattern1_notes, pattern1_tempo, sizeof(pattern1_notes) / sizeof(pattern1_notes[0]));
                break;
            case 2:
                playTune(pattern2_notes, pattern2_tempo, sizeof(pattern2_notes) / sizeof(pattern2_notes[0]));
                break;
            case 3:
                playTune(pattern3_notes, pattern3_tempo, sizeof(pattern3_notes) / sizeof(pattern3_notes[0]));
                break;
            case 4:
                playTune(pattern4_notes, pattern4_tempo, sizeof(pattern4_notes) / sizeof(pattern4_notes[0]));
                break;
        }
    }

    // Reset the buzzer state
    buzzer_set_period(0); // Turn off buzzer
}

void tp() { // Twilight Princess Theme
     // Patterns for unique segments (encoded as IDs)
    const uint8_t pattern1_notes[] = {NOTE_D3, NOTE_E3, NOTE_F3, NOTE_A3, NOTE_C4, NOTE_E4};
    const uint8_t pattern2_notes[] = {NOTE_G4, NOTE_E4, NOTE_C4, NOTE_A3, NOTE_F3, NOTE_E3};
    const uint8_t pattern3_notes[] = {NOTE_A4, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4};
    const uint8_t pattern4_notes[] = {NOTE_G4, NOTE_B4, NOTE_D6, NOTE_A6, NOTE_E6, NOTE_D6};

    const uint8_t pattern1_tempo[] = {4, 4, 4, 4, 4, 4};
    const uint8_t pattern2_tempo[] = {3, 3, 3, 3, 3, 3};
    const uint8_t pattern3_tempo[] = {5, 4, 4, 4, 4, 4};
    const uint8_t pattern4_tempo[] = {3, 3, 3, 3, 3, 3};

    // Sequence of patterns to play
    const uint8_t sequence[] = {1, 1, 1, 2, 2, 3, 4};

    // Play each pattern in sequence
    for (int i = 0; i < sizeof(sequence) / sizeof(sequence[0]); i++) {
        switch (sequence[i]) {
            case 1:
                playTune(pattern1_notes, pattern1_tempo, sizeof(pattern1_notes) / sizeof(pattern1_notes[0]));
                break;
            case 2:
                playTune(pattern2_notes, pattern2_tempo, sizeof(pattern2_notes) / sizeof(pattern2_notes[0]));
                break;
            case 3:
                playTune(pattern3_notes, pattern3_tempo, sizeof(pattern3_notes) / sizeof(pattern3_notes[0]));
                break;
            case 4:
                playTune(pattern4_notes, pattern4_tempo, sizeof(pattern4_notes) / sizeof(pattern4_notes[0]));
                break;
        }
    }

    // Reset the buzzer state
    buzzer_set_period(0); // Turn off buzzer
}
