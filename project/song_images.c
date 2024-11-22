#include "lcdutils.h"
#include "lcddraw.h"

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
