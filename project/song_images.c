#include "lcdutils.h"
#include "lcddraw.h"

void drawFurEliseImage() {
  clearScreen(COLOR_RED);
  drawString5x7(30, 30, "Fur Elise", COLOR_WHITE, COLOR_RED);
}

void drawHappyBdayImage() {
  clearScreen(COLOR_ORANGE);
  drawString5x7(30, 30, "Happy Birthday", COLOR_BLACK, COLOR_ORANGE);
}

void drawMarioImage() {
  clearScreen(COLOR_BROWN);
  drawString5x7(30, 30, "Mario Theme", COLOR_WHITE, COLOR_BROWN);
}

void drawRunaweyImage() {
  clearScreen(COLOR_GREEN);
  drawString5x7(30, 30, "Runawey", COLOR_BLACK, COLOR_GREEN);
}
