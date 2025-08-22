#ifndef DISPLAY_UI_H
#define DISPLAY_UI_H

#include <TFT_eSPI.h>

void renderDisplay(TFT_eSPI &tft, float value) {
  tft.fillRect(0, 0, 240, 60, TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.printf("Value: %.4f", value);
}

#endif