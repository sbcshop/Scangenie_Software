/*
 * This code shows how you can send Scanned Data on Local Webserver
 */
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <Adafruit_GFX.h>    
#include <Adafruit_ST7789.h> 
#include <SPI.h>

#include "index.h"  //Web page header file

WebServer server(80);

#include "SoftwareSerial.h"
SoftwareSerial softSerial(18, 17); //RX, TX

#include "DE2120_Arduino_Library.h" 
DE2120 scanner;

#define BUFFER_LEN 40
char scanBuffer[BUFFER_LEN];


// SPI Configuration for TFT display 
#define TFT_CS        10    // SPI Chip select pin
#define TFT_RST       14    // Display reset pin 
#define TFT_DC        13    // Data/Command pin
#define TFT_MOSI      11    // Data out
#define TFT_SCLK      12    // SPI Clock out
#define BACKLIGHT     5     // Display Backlight connected to IO5 pin

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

//Enter your SSID and PASSWORD
const char* ssid = "Your Network SSID Name";
const char* password = "Network Password";

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
 
void handleData() {
  
 if (scanner.readBarcode(scanBuffer, BUFFER_LEN))
  {
    Serial.print("Data : ");
    for (int i = 0; i < strlen(scanBuffer); i++)
      Serial.print(scanBuffer[i]);
    Serial.println();
    tft.fillScreen(ST77XX_BLACK);
    tft.setTextWrap(true);
    tft.setCursor(10, 30);
    tft.setTextSize(2);
    tft.setTextColor(ST77XX_YELLOW);
    tft.println(scanBuffer);
    //delay(500);
  }
 
 server.send(200, "text/plane", scanBuffer); //Send Scan Data value only to client 
}

//===============================================================
// Setup
//===============================================================

void setup(void){
  Serial.begin(115200); // Configure and setup serial communication
  pinMode(BACKLIGHT, OUTPUT); // Set BackLight pin as OUTPUT
  digitalWrite(BACKLIGHT,HIGH); // Turn on BackLight

  /*
  //ESP32 As access point
    WiFi.mode(WIFI_AP); //Access Point mode
    WiFi.softAP(ssid, password);
  */

//ESP32 connects to your wifi -----------------------------------
  WiFi.mode(WIFI_STA); //Connect to your wifi
  WiFi.begin(ssid, password);

  Serial.println("Connecting to ");
  Serial.print(ssid);

  //Wait for WiFi to connect
  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
      Serial.print(".");
    }

  tft.init(135, 240);   // initialize TFT display
  tft.fillScreen(ST77XX_BLACK); // clear screen
  tft.setRotation(3);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setCursor(10, 50);
  tft.setTextSize(4);
  tft.print("ScanGenie");

  if (scanner.begin(softSerial) == false)
  {
    Serial.println("Scanner did not respond. Please check wiring.");
    Serial.println("Did you scan the POR232 barcode? Freezing...");
    Serial.println("Change mode to TTL: https://github.com/sbcshop/Scangenie_Software/blob/main/README.md#mode-setup");
    tft.setTextSize(2);
    tft.fillScreen(ST77XX_BLACK);
    displayText("Set Device in TTL Mode", ST77XX_RED, 10, 10 );
    displayText("OR", ST77XX_YELLOW, 10, 30 );
    displayText("Check Scanner Wiring", ST77XX_RED, 10, 50 );
    while (1);
  }
  Serial.println("Scanner is ready!");
  delay(1000);
  tft.fillScreen(ST77XX_BLACK);
  
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your device
  Serial.println("Enter above IP address into your browser,\nAnd Scan any Barcode/QR code by pressing Scan Button to view Data");

  tft.setTextSize(2);
  tft.fillScreen(ST77XX_BLACK);
  displayText("Connected to ", ST77XX_YELLOW, 10, 10 );
  displayText(ssid, ST77XX_CYAN, 10, 30 );
  displayText("IP address: ", ST77XX_YELLOW, 10, 60 );
  displayText(WiFi.localIP().toString(), ST77XX_CYAN, 10, 80 );
//----------------------------------------------------------------
 
  server.on("/", handleRoot);      //This is display page
  server.on("/readScanData", handleData);//To get update of Data Value
 
  server.begin();    //Start server
  Serial.println("HTTP server started");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop(void){
  server.handleClient();
  delay(1);
}

void displayText(String text, uint16_t color, int x, int y) {
  tft.setCursor(x, y);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}
