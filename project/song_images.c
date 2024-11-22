#include "lcdutils.h"
#include "lcddraw.h"

void drawDefault(u_int colorBGR, const char *name) {
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

void drawHarp(u_int x, u_int y, u_int size) {
  // Clear the screen with a background color
  clearScreen(COLOR_BROWN);
u_int harpColor = COLOR_GOLD;   // Base color of the harp
  u_int stringColor = COLOR_WHITE; // Strings of the harp

  // Draw the base of the harp (semi-circle arc)
  for (int row = 0; row < size / 2; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(x + col, y + row, harpColor);
    }
  }

  // Draw the left and right decorative arms
  for (int row = 0; row < size / 2; row++) {
    for (int col = -size / 8; col <= size / 8; col++) {
      // Left arm
      drawPixel(x - size / 2 + col, y + row, harpColor);
      // Right arm
      drawPixel(x + size / 2 + col, y + row, harpColor);
    }
  }

  // Draw the harp strings
  int stringSpacing = size / 10;
  for (int i = 0; i <= 6; i++) { // Draw 7 strings
    for (int row = 0; row < size / 2; row++) {
      drawPixel(x - size / 3 + i * stringSpacing, y + row, stringColor);
    }
  }

  // Add decorative details (small arcs for top and bottom edges)
  for (int row = size / 2 - 3; row < size / 2; row++) {
    for (int col = -row / 2; col <= row / 2; col++) {
      drawPixel(x + col, y + row + size / 2, harpColor); // Bottom arc
    }
  }
  
  // Draw text for Zelda's Lullaby
  drawString5x7(20, screenHeight - 20, "Zelda's Lullaby", COLOR_GOLD, COLOR_BROWN);
}

void drawHyruleShieldWithSword(u_int x, u_int y, u_int size) {
  clearScreen(COLOR_DARK_GREEN);
  u_int shieldColor = COLOR_BLUE;    // Base color of the shield
  u_int trimColor = COLOR_GRAY;      // Shield trim color
  u_int triforceColor = COLOR_GOLD;  // Triforce color
  u_int crestColor = COLOR_RED;      // Crest color
  u_int borderColor = COLOR_BLACK;   // Border color
  u_int swordBladeColor = COLOR_GRAY; // Sword blade color
  u_int swordHiltColor = COLOR_BLUE; // Sword hilt color
  u_int swordAccentColor = COLOR_YELLOW; // Sword accent color

  // Draw the sword (straight vertical line through the shield)
  int swordWidth = size / 10; // Thickness of the sword blade
  int swordHeight = size * 2; // Height of the sword blade

  // Sword blade
  for (int row = -swordHeight / 2; row < swordHeight / 2; row++) {
    for (int col = -swordWidth; col <= swordWidth; col++) {
      drawPixel(x + col, y + row, swordBladeColor);
    }
  }

  // Sword hilt (horizontal part of the sword)
  int hiltWidth = size / 2;
  int hiltThickness = size / 8;

  for (int row = -hiltThickness; row <= hiltThickness; row++) {
    for (int col = -hiltWidth; col <= hiltWidth; col++) {
      drawPixel(x + col, y - swordHeight / 3 + row, swordHiltColor);
    }
  }

  // Sword hilt accent (yellow part in the center)
  int accentWidth = hiltWidth / 3;
  for (int row = -hiltThickness / 2; row <= hiltThickness / 2; row++) {
    for (int col = -accentWidth; col <= accentWidth; col++) {
      drawPixel(x + col, y - swordHeight / 3 + row, swordAccentColor);
    }
  }

  // Now draw the shield on top of the sword
  drawHyruleShield(x, y, size);
}

void drawHyruleShield(u_int x, u_int y, u_int size) {
  u_int shieldColor = COLOR_BLUE;    // Base color of the shield
  u_int trimColor = COLOR_GRAY;      // Shield trim color
  u_int triforceColor = COLOR_GOLD;  // Triforce color
  u_int crestColor = COLOR_RED;      // Crest color
  u_int borderColor = COLOR_BLACK;   // Border color

  // Draw the rounded shield border
  for (int row = 0; row < size; row++) {
    int width = size - row / 2;  // Gradually reduce width for rounded edges
    for (int col = -width; col <= width; col++) {
      drawPixel(x + col, y + row, borderColor);
    }
  }

  // Draw the blue inner shield
  for (int row = 1; row < size - 2; row++) {
    int width = size - row / 2 - 2;  // Slightly smaller for inner shape
    for (int col = -width; col <= width; col++) {
      drawPixel(x + col, y + row, shieldColor);
    }
  }

  // Draw the triforce emblem
  int triforceHeight = size / 5;
  int triforceBaseRow = y + size / 4;
  int triforceBaseCol = x;

  for (int row = 0; row < triforceHeight; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(triforceBaseCol + col, triforceBaseRow + row, triforceColor);
    }
  }

  // Draw the red crest below the triforce
  int crestHeight = size / 6;
  int crestBaseRow = triforceBaseRow + triforceHeight + 2;

  for (int row = 0; row < crestHeight; row++) {
    for (int col = -row * 3 / 2; col <= row * 3 / 2; col++) {  // Wider crest
      drawPixel(x + col, crestBaseRow + row, crestColor);
    }
  }

  // Add decorative gray details around the crest
  int detailRow = crestBaseRow - 3;
  int detailSize = crestHeight / 2;
  for (int row = 0; row < detailSize; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(x - size / 4 + col, detailRow + row, trimColor); // Left detail
      drawPixel(x + size / 4 + col, detailRow + row, trimColor); // Right detail
    }
  }

  // Draw bottom point of the shield (rounded)
  for (int row = size - 3; row < size; row++) {
    int width = size / 8;  // Bottom point width
    for (int col = -width; col <= width; col++) {
      drawPixel(x + col, y + row, trimColor);
    }
  }
  drawString5x7(20, 120, "Ocarina of Time", COLOR_RED, COLOR_DARK_GREEN);
}

void drawMajorasMask(u_int x, u_int y, u_int pixelSize) {
  clearScreen(COLOR_GRAY);

  // Colors for the mask
  u_int colors[] = {
    COLOR_GRAY, COLOR_RED, COLOR_YELLOW, COLOR_BLUE, COLOR_BLACK, COLOR_WHITE, COLOR_CYAN
  };

  // Compressed mask pattern (hex digits: 0=GRAY, 1=RED, 2=YELLOW, 3=BLUE, etc.)
  const char maskPattern[] = {
    0x00333, 0x03113, 0x31115, 0x31544, 0x11546, 0x11146, 0x11144,
    0x11546, 0x31544, 0x03113, 0x00333, 0x00311, 0x00033, 0x00003, 0x00000
  };

  // Draw each row of the mask
  for (int row = 0; row < 15; row++) {
    int pattern = maskPattern[row];
    for (int col = 0; col < 15; col++) {
      int colorIndex = (pattern >> (4 * (14 - col))) & 0xF; // Extract each hex digit
      u_int color = colors[colorIndex]; // Get corresponding color

      // Draw the pixel as a rectangle
      for (int dy = 0; dy < pixelSize; dy++) {
        for (int dx = 0; dx < pixelSize; dx++) {
          drawPixel(x + col * pixelSize + dx, y + row * pixelSize + dy, color);
        }
      }
    }
  }
}
