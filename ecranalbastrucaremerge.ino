#include <TFT_eSPI.h>
#include <SPI.h>
#include "Pixelmare_little_endian.h"  // header file with #define and PixelmareImage[]

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  tft.setSwapBytes(true);  // For little-endian RGB565 data

  // Cast image data to uint16_t* since it's declared as uint8_t[]
  tft.pushImage(0, 0, PixelmareImage_WIDTH, PixelmareImage_HEIGHT, (uint16_t*)PixelmareImage);
}

void loop() {}