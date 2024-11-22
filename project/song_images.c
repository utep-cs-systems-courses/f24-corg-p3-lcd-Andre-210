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
  u_int shieldColor = COLOR_BLUE;   // Base color of the shield
  u_int trimColor = COLOR_SILVER;  // Color for shield trim
  u_int emblemColor = COLOR_RED;   // Color for the Hyrule crest
  u_int triforceColor = COLOR_GOLD; // Color for the Triforce

  // Outer shape (shield trim)
  for (int row = 0; row < size; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(x + col, y + row, trimColor);
    }
  }

  // Inner shape (blue part of the shield)
  for (int row = 1; row < size - 2; row++) {
    for (int col = -(row - 1); col <= (row - 1); col++) {
      drawPixel(x + col, y + row, shieldColor);
    }
  }

  // Triforce emblem
  int triforceBaseRow = y + size / 3;
  int triforceBaseCol = x;
  int triforceHeight = size / 6;

  for (int row = 0; row < triforceHeight; row++) {
    for (int col = -row; col <= row; col++) {
      drawPixel(triforceBaseCol + col, triforceBaseRow + row, triforceColor);
    }
  }

  // Red Hylian crest
  int crestRowStart = triforceBaseRow + triforceHeight + 2;
  int crestWidth = size / 4;

  for (int row = 0; row < triforceHeight; row++) {
    for (int col = -crestWidth + row; col <= crestWidth - row; col++) {
      drawPixel(x + col, crestRowStart + row, emblemColor);
    }
  }

  // Bottom shield points (adding to the triangular base)
  for (int row = size - 3; row < size; row++) {
    for (int col = -2; col <= 2; col++) {
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
