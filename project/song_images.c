#include "lcdutils.h"
#include "lcddraw.h"

void drawDefault(u_int colorBGR, char *name) {
  clearScreen(colorBGR);
  drawString5x7(10, 15, "The Legend of Zelda", COLOR_GOLD, colorBGR);
  // find the height and width of the screen
  u_char width = screenWidth, height = screenHeight;
  // find the location of the top triangle
  int centerCol = width / 2, centerRow = height / 4;
  // set the length it each triangle
  int sideLength = 20; 

  // draw the top triangle
  for (int row = 0; row < sideLength; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(centerCol + col, centerRow + row, COLOR_GOLD);
    }
  }

  // draw the bottom-left triangle
  // find the location of the triangle
  int leftCenterCol = centerCol - sideLength;
  int leftCenterRow = centerRow + sideLength;
  for (int row = 0; row < sideLength; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(leftCenterCol + col, leftCenterRow + row, COLOR_GOLD);
    }
  }

  // draw the bottom-right triangle
  // find the location of the triangle
  int rightCenterCol = centerCol + sideLength;
  int rightCenterRow = centerRow + sideLength;
  for (int row = 0; row < sideLength; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(rightCenterCol + col, rightCenterRow + row, COLOR_GOLD);
    }
  }
  drawString5x7(35, height - 20, name, COLOR_WHITE, colorBGR);
}

void drawHarp(u_int x, u_int y, u_int size, u_int colorBGR, char *name) {
  // clear the screen with a background color
  clearScreen(colorBGR);
  u_int harpColor = COLOR_GOLD;                // base color of the harp
  u_int stringColor = COLOR_WHITE;             // strings of the harp

  // draw the base of the harp (semi-circle arc)
  for (int row = 0; row < size / 2; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(x + col, y + row, harpColor);
    }
  }

  // draw the left and right decorative arms
  for (int row = 0; row < size / 2; row++) {
    for (int col = -size / 8; col <= size / 8; col++) {
      // left arm
      drawPixel(x - size / 2 + col, y + row, harpColor);
      // right arm
      drawPixel(x + size / 2 + col, y + row, harpColor);
    }
  }

  // draw the harp strings
  int stringSpacing = size / 10;
  for (int i = 0; i <= 6; i++) {                 // draw 7 strings
    for (int row = 0; row < size / 2; row++) {
      drawPixel(x - size / 3 + i * stringSpacing, y + row, stringColor);
    }
  }

  // add decorative details (small arcs for top and bottom edges)
  for (int row = size / 2 - 3; row < size / 2; row++) {
    for (int col = -row / 2; col <= row / 2; col++) {
      drawPixel(x + col, y + row + size / 2, harpColor);      // bottom arc
    }
  }
  
  // draw text for Zelda's Lullaby
  drawString5x7(20, screenHeight - 20, name, COLOR_GOLD, colorBGR);
}

void drawHyruleShieldWithSword(u_int x, u_int y, u_int size, u_int colorBGR, char *name) {
  clearScreen(COLOR_DARK_GREEN);
  u_int shieldColor = COLOR_BLUE;         // base color of the shield
  u_int trimColor = COLOR_GRAY;           // shield trim color
  u_int triforceColor = COLOR_GOLD;       // triforce color
  u_int crestColor = COLOR_RED;           // crest color
  u_int borderColor = COLOR_BLACK;        // border color
  u_int swordBladeColor = COLOR_GRAY;     // sword blade color
  u_int swordHiltColor = COLOR_BLUE;      // sword hilt color
  u_int swordAccentColor = COLOR_YELLOW;  // sword accent color

  // draw the sword (straight vertical line through the shield)
  int swordWidth = size / 10;       // thickness of the sword blade
  int swordHeight = size * 2;       // height of the sword blade

  // sword blade
  for (int row = -swordHeight / 2; row < swordHeight / 2; row++) {
    for (int col = -swordWidth; col <= swordWidth; col++) {
      drawPixel(x + col, y + row, swordBladeColor);
    }
  }

  // sword hilt (horizontal part of the sword)
  int hiltWidth = size / 2;
  int hiltThickness = size / 8;

  for (int row = -hiltThickness; row <= hiltThickness; row++) {
    for (int col = -hiltWidth; col <= hiltWidth; col++) {
      drawPixel(x + col, y - swordHeight / 3 + row, swordHiltColor);
    }
  }

  // sword hilt accent (yellow part in the center)
  int accentWidth = hiltWidth / 3;
  for (int row = -hiltThickness / 2; row <= hiltThickness / 2; row++) {
    for (int col = -accentWidth; col <= accentWidth; col++) {
      drawPixel(x + col, y - swordHeight / 3 + row, swordAccentColor);
    }
  }

  // draw the shield on top of the sword
  drawHyruleShield(x, y, size, colorBGR, name);
}

void drawHyruleShield(u_int x, u_int y, u_int size, u_int colorBGR, char *name) {
  u_int shieldColor = COLOR_BLUE;        // base color of the shield
  u_int trimColor = COLOR_GRAY;          // shield trim color
  u_int triforceColor = COLOR_GOLD;      // triforce color
  u_int crestColor = COLOR_RED;          // crest color
  u_int borderColor = COLOR_BLACK;       // border color

  // draw the rounded shield border
  for (int row = 0; row < size; row++) {
    int width = size - row / 2;           // gradually reduce width for rounded edges
    for (int col = -width; col <= width; col++) {
      drawPixel(x + col, y + row, borderColor);
    }
  }

  // draw the blue inner shield
  for (int row = 1; row < size - 2; row++) {
    int width = size - row / 2 - 2;        // slightly smaller for inner shape
    for (int col = -width; col <= width; col++) {
      drawPixel(x + col, y + row, shieldColor);
    }
  }

  // draw the triforce emblem
  int triforceHeight = size / 5;
  int triforceBaseRow = y + size / 4;
  int triforceBaseCol = x;

  for (int row = 0; row < triforceHeight; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(triforceBaseCol + col, triforceBaseRow + row, triforceColor);
    }
  }

  // draw the red crest below the triforce
  int crestHeight = size / 6;
  int crestBaseRow = triforceBaseRow + triforceHeight + 2;

  for (int row = 0; row < crestHeight; row++) {
    for (int col = -row * 3 / 2; col <= row * 3 / 2; col++) {     // wider crest
      drawPixel(x + col, crestBaseRow + row, crestColor);
    }
  }

  // add decorative gray details around the crest
  int detailRow = crestBaseRow - 3;
  int detailSize = crestHeight / 2;
  for (int row = 0; row < detailSize; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(x - size / 4 + col, detailRow + row, trimColor);      // left detail
      drawPixel(x + size / 4 + col, detailRow + row, trimColor);      // right detail
    }
  }

  // draw bottom point of the shield (rounded)
  for (int row = size - 3; row < size; row++) {
    int width = size / 8;                    // bottom point width
    for (int col = -width; col <= width; col++) {
      drawPixel(x + col, y + row, trimColor);
    }
  }
  drawString5x7(20, 120, name, COLOR_RED, colorBGR);
}
