#include "lcdutils.h"
#include "lcddraw.h"

void drawDefault() {
  clearScreen(COLOR_BLUE);
  int col = 0, row = 0; 
  int centerCol = width/2, centerRow = height/2;
  for (row = 0; row < 20; row++) { 
    for (col = -row; col <= row; col+=2) {
      drawPixel(centerCol + col, centerRow + row, COLOR_PINK);
      }
    }
}
void drawZeldasLullaby() {
  clearScreen(COLOR_RED);
  drawString5x7(30, 30, "Zelda's Lullaby", COLOR_WHITE, COLOR_RED);
}

void drawOOT() {
  clearScreen(COLOR_ORANGE);
  drawString5x7(30, 30, "Ocarina of Time Main Theme", COLOR_BLACK, COLOR_ORANGE);
}

void drawSOH() {
  clearScreen(COLOR_BROWN);
  drawString5x7(30, 30, "Song of Healing", COLOR_WHITE, COLOR_BROWN);
}

void drawTP() {
  clearScreen(COLOR_GREEN);
  drawString5x7(30, 30, "Twilight Princess Theme", COLOR_BLACK, COLOR_GREEN);
}
