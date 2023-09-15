# ScanGenie_Software
<img src="">
ScanGenie is your powerful barcode solution with a 1.14" LCD screen, rapid Barcode/QR code scanner, versatile UART communication, Type-C USB port, and a buzzer. It simplifies complex barcode decoding, effortlessly connects to the cloud, and provides real-time feedback. Supporting 20 barcode symbologies, it's an open-source platform for developers and enthusiasts. Say goodbye to tough barcode challenges with ScanGenie's simplicity and versatility.

This GitHub page offers a step-by-step tutorial for using ScanGenie. 
### Features

### Specification

### Pinouts

### Interfacing Details
- Display interfacing with ESP32
    | ESP32 | Display | Function |
    |---|---|---|
    | IO12 | LCD_CLK | Clock pin of SPI interface for Display|
    | IO11 | LCD_DIN | MOSI (Master OUT Slave IN) pin of SPI interface|
    | IO10 | LCD_CS | Chip Select pin of SPI interface|
    | IO13 | LCD_DC| Data/Command (MISO) pin of SPI interface|
    | IO14 | LCD_RST | Display Reset pin |
    | IO5  | BL | Backlight of display|

- ESP32 and DE2120 Scanner Module interfacing
    | ESP32| DE2120 Scanner | Function |
    |---|---|---|
    |IO17/U1TXD | B_RX | UART Communication Pin |
    |IO18/U1RXD | B_TX | UART Communication Pin |
  
- Buttons, Buzzer and LED Interfacing with ESP32
    | ESP32 | Hardware | Function |
    |---|---|---|
    |IO0 | BOOT |Boot button |
    |IO7 | SCAN | Scan Button |
  
  
   

### 1. Configure and Setup Development Environment
   - Download Arduino IDE from [official site](https://www.arduino.cc/en/software) and install into your system. We have use Arduino IDE 1.8.19
   - Once installation done will add ESP32 S3 board support into IDE, for this first you need to add below link into preference:
     
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
     
     Select File > Preference, and add link as show in below image,
      <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/preference_board.gif" />
      
   - Now will install ESP32 based boards as shown in below image,

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/install_ESP32boards.gif" />
     
   - Once done, keeping default settings select the ESP32S3 Dev Module with suitable com port (may be different in your case) as shown below, 

     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/select_esp32_with_comport.gif">
     
     
### 2. Installing Libraries
   - Download [library zip file]() provided here in github.
   - Extract and copy files inside Document > Arduino > Libraries folder. Make sure to restart Arduino IDE whenever you update or add any libraries.

     <img src= "https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/library_files_path.png" />
     
### 3. Testing First Code
   - At this step you are all set to test codes, for easy getting started we have provided various demo [example codes]() in github which you can download and try. 
   - Open one example code in Arduino and make sure you have selected correct board with suitable com port, click on upload button to transfer code on ESP32 of Scangenie.
     <img src="https://github.com/sbcshop/3.2_Touchsy_ESP-32_Resistive_Software/blob/main/images/upload_process.gif">
   - Checkout other examples below and build your own custom program codes using those references.

### Example Codes
   - [Example 1]() : Display demo code
   - [Example 2]() : Button & Buzzer testing with display code
   - and [Many more...]()

   Now you are ready to try out your own codes, **_Happy Coding!_**
   
## Resources
  * [Schematic](https://github.com/sbcshop/Scangenie_Hardware/blob/main/Design%20Data/Sch_Scangenie.pdf)
  * [Hardware Files](https://github.com/sbcshop/Scangenie_Hardware)
  * [Step File](https://github.com/sbcshop/Scangenie_Hardware/blob/main/Mechanical%20Data/ScanGenie.step)
  * [Getting Started with ESP32 in Arduino](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
  * [ESP32 S3 Hardware Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/index.html)
  * [ESP32 S3 Datasheet](https://github.com/sbcshop/3.2_Touchsy_ESP-32_Capacitive_Software/blob/main/documents/esp32-s3_datasheet_en.pdf)
  * [Arduino IDE 1 overview](https://docs.arduino.cc/software/ide-v1/tutorials/Environment)

## Related Products
  * [Barcode HAT](https://shop.sb-components.co.uk/products/barcode-hat-for-raspberry-pi) 
   
     ![Barcode_HAT](https://shop.sb-components.co.uk/cdn/shop/products/4_b21d715d-e0ec-45a6-a743-fed89e77b3c3.jpg?v=1665556430&width=300)   

  * [Barcode Scanner Module, 1D/2D Codes Reader](https://shop.sb-components.co.uk/products/barcode-scanner-module-1d-2d-codes-reader) 
   
     ![Barcode_Scanner_Module](https://shop.sb-components.co.uk/cdn/shop/products/barcode-scanner-module-1_1.jpg?v=1612257001&width=300) 

  * [1D 2D CMOS DE2120 Barcode Scanner Sensor](https://shop.sb-components.co.uk/products/1d-2d-cmos-de2120-barcode-scanner-sensor) 
   
     ![1D_2D_CMOS_DE2120_Barcode Scanner_Sensor](https://shop.sb-components.co.uk/cdn/shop/products/16410-2D_Barcode_Scanner_Module_-_DE2120-01.jpg?v=1657026105&width=300) 

 
## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact support@sb-components.co.uk for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>
