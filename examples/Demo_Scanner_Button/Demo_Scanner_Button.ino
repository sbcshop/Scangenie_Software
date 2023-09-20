/* In this demo code ScanGenie use to Scan Barcode/QR code by pressing Scan Button
 * Point ScanGenie to any Barcode/QR code and press onboard Scan button  */

#include <Adafruit_GFX.h>    // graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789 (display controller)
#include <SPI.h>
#include "SoftwareSerial.h"
#include "DE2120_Arduino_Library.h"

SoftwareSerial softSerial(18, 17); // RX, TX - serial interface connection between ESP32 and DE2120 scanner

DE2120 scanner;

#define BUFFER_LEN 40
char scanBuffer[BUFFER_LEN];


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
  Serial.begin(115200);
  Serial.println("Device is ready");
  pinMode(BACK_LIGHT, OUTPUT); // Back Light
  digitalWrite(BACK_LIGHT,HIGH);
  
  tft.init(135, 240); 
  tft.setRotation(3); // Change display rotation as per requirement, value-> 0 (defualt), 1, 2, 3
  tft.fillScreen(ST77XX_BLACK);
  delay(100);
  
  if (scanner.begin(softSerial) == false)
  {
    Serial.println("Scanner did not respond. Please check wiring.");
    Serial.println("Did you scan the POR232 barcode? Freezing...");
    Serial.println("Change mode to TTL: https://github.com/sbcshop/Scangenie_Software/blob/main/README.md#mode-setup");
    while (1);
  }
  
  Serial.println("Scanner is ready!");
  tft.fillScreen(ST77XX_BLACK); // clear screen
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(20, 30);
  tft.setTextSize(2);
  tft.print("Press Button");
  tft.setCursor(20, 50);
  tft.print("to Scan");
  delay(1000);
}

void loop()
{
  if (scanner.readBarcode(scanBuffer, BUFFER_LEN))
  {
    Serial.print("Data : ");
    for (int i = 0; i < strlen(scanBuffer); i++)
      Serial.print(scanBuffer[i]);
      
    Serial.println();
    if (strlen(scanBuffer)){
      tft.fillScreen(ST77XX_BLACK);
      tft.setTextWrap(true);
      tft.setCursor(20, 20);
      tft.setTextColor(ST77XX_YELLOW);
      tft.setTextSize(2);
      tft.println(scanBuffer);
      delay(500);
      tft.fillScreen(ST77XX_BLACK);
    }
    
  }
  delay(200);
}
