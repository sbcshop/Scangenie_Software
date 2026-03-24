/* In this demo code ScanGenie use to Scan Barcode/QR code by pressing Scan Button
 * Point ScanGenie to any Barcode/QR code and press onboard Scan button  */

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include "DE2120_Arduino_Library.h"

// ------------------ SCANNER ------------------
HardwareSerial DE_Serial(2);   // Use UART2
DE2120 scanner;

#define BUFFER_LEN 120
char responseBuffer[BUFFER_LEN];

// ------------------ DISPLAY ------------------
#define TFT_CS   10
#define TFT_RST  14 
#define TFT_DC   13
#define TFT_MOSI 11 
#define TFT_SCLK 12
#define BACK_LIGHT 5

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// ------------------ SETUP ------------------
void setup()
{
  Serial.begin(115200);
  Serial.println("Device is ready");

  // Start Hardware Serial (VERY IMPORTANT)
  DE_Serial.begin(9600, SERIAL_8N1, 18, 17); // RX=18, TX=17

  // Display setup
  pinMode(BACK_LIGHT, OUTPUT);
  digitalWrite(BACK_LIGHT, HIGH);

  tft.init(135, 240);
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);
  delay(100);

  // Initialize Scanner with Hardware Serial
  if (scanner.begin(DE_Serial) == false)
  {
    Serial.println("Scanner did not respond. Please check wiring.");
    Serial.println("Make sure scanner is in TTL mode!");
    while (1);
  }

  Serial.println("Scanner is ready!");

  // Initial display
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(20, 30);
  tft.setTextSize(2);
  tft.print("Press Button");
  tft.setCursor(20, 50);
  tft.print("to Scan");

  delay(1000);
}

// ------------------ LOOP ------------------
void loop()
{
  if (scanner.readBarcode(responseBuffer, BUFFER_LEN))
  {
    Serial.print("Scanned Data: ");
    Serial.println(responseBuffer);

    // Display on TFT
    tft.fillScreen(ST77XX_BLACK);

    tft.setCursor(0, 20);
    tft.setTextSize(2);
    tft.setTextColor(ST77XX_GREEN);
    tft.println("Scanned:");

    tft.setCursor(0, 60);
    tft.setTextColor(ST77XX_WHITE);
    tft.println(responseBuffer);
  }

  delay(100);
}
