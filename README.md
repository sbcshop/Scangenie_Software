# ScanGenie_Software

<img src="https://github.com/sbcshop/Scangenie_Software/blob/main/images/scangenie_banner.jpg">

ScanGenie is your powerful barcode solution with a 1.14" LCD screen, rapid Barcode/QR code scanner, versatile UART communication, Type-C USB port, and a buzzer. It simplifies complex barcode decoding, effortlessly connects to the cloud, and provides real-time feedback. Supporting 20 barcode symbologies, it's an open-source platform for developers and enthusiasts. Say goodbye to tough barcode challenges with ScanGenie's simplicity and versatility.

This GitHub page offers a step-by-step tutorial for using ScanGenie. 

### Features : 
- Powered with ESP32 makes it IoT enabled device to connect internet Cloud using WiFi and BLE for local wireless transmission
- 1.14" TFT display for visual interaction
- Read all mainstream 1D 2D barcodes in the market easily
- Reads 20 Different Barcode Symbologies, CMOS camera
- Two type C Support : 
    - for direct Scanner access  
    - for programming/power 
- High brightness, dark environment scanning 
- Support multiple systems and languages, secondary development.
- Additional GPIO breakouts for interfacing other peripherals
- Separate Scan button along with Reset and boot buttons for on the go scanning. 
- Onboard buzzer provides audible alerts and notifications for enhanced user experience and system feedback.
- Breadboard compatible for easy DIY breadboarding projects
  
### Specification : 
- ESP32-S3 series of SoCs having Xtensa® dual-core 32-bit LX7 microprocessor, 2.4 GHz Wi-Fi (802.11 b/g/n) and Bluetooth® 5 (LE), Flash up to 16 MB, PSRAM up to 8 MB 
- Board supply voltage:  5V
- Operating voltage of pins: 3.3V
- Display resolution 240 × 135 pixels
- ST7789V2 Display Driver
- Appearance: RGB, Colors: 65K
- Reads 20 different symbologies:
  - 1D Symbologies-> UPC-A, UPC-E, EAN-8, EAN-13, Code 128, GS1-128, Code 39, Code 93, Code 11, Interleaved 2-of-5, Matrix 2-of-5, Industrial 2-of-5, Codabar, MSI, GS1 DataBar, Datalogic 2-of-5
  - 2D Symbologies->  QR Code,Data Matrix, PDF 417, Micro PDF 417,

- Scanner Resolution: 640*480 
- Communication Mode: USB(USB-KBW, USB-COM),TTL
- Operating Temperature: -20℃ to 50℃
- Storage Temperature: -40℃ to 70℃

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
    |IO18 | B_RX | UART Communication Pin |
    |IO17 | B_TX | UART Communication Pin |
  
- Buttons and Trigger pin 
    | ESP32 | Hardware | Function |
    |---|---|---|
    |IO0 | BOOT |Boot button |
    |IO7 | B_SCAN | Scan Trigger Pin |
  
  

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
   - [Example 1]() : Display Demo code
   - [Example 2]() : Scanning Barcode/QR Code using Scan Button
   - [Example 3]() : Automatic Scanning Barcode/QR code after regular interval of Time
   - and [Many more...]()

   Now you are ready to try out your own codes, **_Happy Coding!_**

### Mode Setup
- **TTL Mode**
  TTL mode is default mode in which DE2120 Scanner will work in co-ordination with ESP32 controller of ScanGenie using UART communication. If anyone how mode is different you can follow below steps to get device into TTL mode. 
  - First step Scan the below barcode by Pressing onboard Scan button of ScanGenie. This will put device into TTL mode
    
    <img src="https://github.com/sbcshop/Pi-Barcode-HAT/raw/main/images/ttl_rs232.JPG">
    
  - Now to set Baud Rate 9600 by scanning below Barcode, even you can set different Baud Rate by refering Manual provided in this repo.
    
    <img src="https://github.com/sbcshop/Pi-Barcode-HAT/raw/main/images/baudrate.JPG">
    
  - **TTL mode is required** if you want **to try** various **code example** provided in this GitHub repo.
  
  
- **USB-KBW Mode**

  You can also use this ScanGenie with USB cable for reading Barcode/Scanner without onboard ESP32 controller board.

  - Connect type C cable to "Barcode" side instead of "PROG" and other end to your laptop/PC.

  - Now simply scan the below Barcode and so this will set board into USB keyboard mode.
    
    <img src="https://github.com/sbcshop/Pi-Barcode-HAT/raw/main/images/img7.JPG">
    
  - In USB keyboard mode, you just need to open a notepad/word like application and scan any barcode or QR-code to get their number in your system. As shown in image below
    
    <img src="https://github.com/sbcshop/Zero-Barcode-Hat/raw/main/images/SC.PNG" width="539" height="311">
    
  The DE2120 is completely user configurable, you can configure many settings according to your requirement by refering the DE2120 Manual(Barcode manual) provided in this Repo.  
  
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
