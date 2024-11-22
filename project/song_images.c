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
  drawString5x7(10, height - 20, name, COLOR_BLACK, colorBGR);
}

//void drawZeldasLullaby() {
  //clearScreen(COLOR_RED);
  //drawString5x7(10, 15, "The Legend of Zelda", COLOR_YELLOW, COLOR_BLUE);
  // find the height and width of the screen
  //u_char width = screenWidth, height = screenHeight;
  // find the location of the top triangle
  //int centerCol = width / 2, centerRow = height / 4;
  // set the length it each triangle
  //int sideLength = 20; 

  // draw the top triangle
  //for (int row = 0; row < sideLength; row++) {
    //for (int col = -row; col <= row; col++) {
      //drawPixel(centerCol + col, centerRow + row, COLOR_YELLOW);
    //}
  //}

  // draw the bottom-left triangle
  // find the location of the triangle
  //int leftCenterCol = centerCol - sideLength;
  //int leftCenterRow = centerRow + sideLength;
  //for (int row = 0; row < sideLength; row++) {
    //for (int col = -row; col <= row; col++) {
      //drawPixel(leftCenterCol + col, leftCenterRow + row, COLOR_YELLOW);
    //}
  //}

  // draw the bottom-right triangle
  // find the location of the triangle
  //int rightCenterCol = centerCol + sideLength;
  //int rightCenterRow = centerRow + sideLength;
  //for (int row = 0; row < sideLength; row++) {
    //for (int col = -row; col <= row; col++) {
      //drawPixel(rightCenterCol + col, rightCenterRow + row, COLOR_YELLOW);
    //}
  //}
//}

void drawHyruleShield(u_int x, u_int y, u_int size) {
  clearScreen(COLOR_DARK_GREEN);
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
}

//void drawSOH() {
  //clearScreen(COLOR_BROWN);
  //drawString5x7(10, 15, "The Legend of Zelda", COLOR_YELLOW, COLOR_BLUE);
  // find the height and width of the screen
  //u_char width = screenWidth, height = screenHeight;
  // find the location of the top triangle
  //int centerCol = width / 2, centerRow = height / 4;
  // set the length it each triangle
  //int sideLength = 20; 

  // draw the top triangle
  //for (int row = 0; row < sideLength; row++) {
    //for (int col = -row; col <= row; col++) {
      //drawPixel(centerCol + col, centerRow + row, COLOR_YELLOW);
    //}
  //}

  // draw the bottom-left triangle
  // find the location of the triangle
  //int leftCenterCol = centerCol - sideLength;
  //int leftCenterRow = centerRow + sideLength;
  //for (int row = 0; row < sideLength; row++) {
    //for (int col = -row; col <= row; col++) {
      //drawPixel(leftCenterCol + col, leftCenterRow + row, COLOR_YELLOW);
    //}
  //}

  // draw the bottom-right triangle
  // find the location of the triangle
  //int rightCenterCol = centerCol + sideLength;
  //int rightCenterRow = centerRow + sideLength;
  //for (int row = 0; row < sideLength; row++) {
    //for (int col = -row; col <= row; col++) {
      //drawPixel(rightCenterCol + col, rightCenterRow + row, COLOR_YELLOW);
    //}
  //}
//}

//void drawTP() {
  //clearScreen(COLOR_GREEN);
  //drawString5x7(10, 15, "The Legend of Zelda", COLOR_YELLOW, COLOR_BLUE);
  // find the height and width of the screen
  //u_char width = screenWidth, height = screenHeight;
  // find the location of the top triangle
  //int centerCol = width / 2, centerRow = height / 4;
  // set the length it each triangle
  //int sideLength = 20; 

  // draw the top triangle
  //for (int row = 0; row < sideLength; row++) {
    //for (int col = -row; col <= row; col++) {
      //drawPixel(centerCol + col, centerRow + row, COLOR_YELLOW);
    //}
  //}

  // draw the bottom-left triangle
  // find the location of the triangle
  //int leftCenterCol = centerCol - sideLength;
  //int leftCenterRow = centerRow + sideLength;
  //for (int row = 0; row < sideLength; row++) {
    //for (int col = -row; col <= row; col++) {
      //drawPixel(leftCenterCol + col, leftCenterRow + row, COLOR_YELLOW);
    //}
  //}

  // draw the bottom-right triangle
  // find the location of the triangle
  //int rightCenterCol = centerCol + sideLength;
  //int rightCenterRow = centerRow + sideLength;
  //for (int row = 0; row < sideLength; row++) {
    //for (int col = -row; col <= row; col++) {
      //drawPixel(rightCenterCol + col, rightCenterRow + row, COLOR_YELLOW);
    //}
  //}
//}
