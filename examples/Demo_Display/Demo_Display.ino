#include <Adafruit_GFX.h>    // graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789 (display controller)
#include <SPI.h>

// Display SPI configuration
#define TFT_CS   10
#define TFT_RST  14 
#define TFT_DC   13

#define TFT_MOSI 11 
#define TFT_SCLK 12

#define BACK_LIGHT 5

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup()
{
  
  pinMode(BACK_LIGHT, OUTPUT); // BackLight pin set as OUTPUT
  digitalWrite(BACK_LIGHT,HIGH); // Turn on BackLight
  
  tft.init(135, 240);  // initialize display with resolution
  tft.setRotation(3); // Change display rotation as per requirement, value-> 0 (defualt), 1, 2, 3
  
  tft.fillScreen(ST77XX_BLACK); // clear screen
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(10, 50);
  tft.setTextSize(4);
  tft.print("ScanGenie");

  tft.setTextSize(2); 
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 20);
  tft.setTextColor(ST77XX_YELLOW);
  tft.println("Thanks for Buying!");
 
  tft.setCursor(0, 60);
  tft.setTextWrap(true);
  tft.setTextColor(ST77XX_BLUE);
  tft.println("SB Components");
  tft.setTextSize(2);
  tft.setCursor(0, 90);
  tft.setTextColor(ST77XX_WHITE);
  tft.println("shop.sb-components.co.uk");
}

void loop()
{
  
}
