#include <TFT_eSPI.h>  // use this lib, not Adafruit
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(0);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("JMD-PS130 V2.0");
  tft.fillRect(20, 50, 50, 50, TFT_RED);
  tft.fillRect(80, 50, 50, 50, TFT_GREEN);
  tft.fillRect(140, 50, 50, 50, TFT_BLUE);
}

void loop() {
  // Nothing here for now
}