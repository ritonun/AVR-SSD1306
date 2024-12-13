#include <ssd1306.h>

void sendCommand(uint8_t command) {
    Wire.beginTransmission(SCREEN_ADDR);
    Wire.write(0x00);
    Wire.write(command);
    Wire.endTransmission();
}


void fillScreen(uint8_t byte) {

  sendCommand(0x20);
  sendCommand(0x01);
 // Set column address range (0 to 127)
  sendCommand(0x21);  // Column address command
  sendCommand(0x00);  // Column start address
  sendCommand(0x7F);  // Column end address (127)

  // Set page address range (0 to 7)
  sendCommand(0x22);  // Page address command
  sendCommand(0x00);  // Page start address
  sendCommand(0x07);  // Page end address (7)

  // Fill the entire screen with white pixels (0xFF = all pixels ON)
  for (int page = 0; page < 8; page++) {  // 8 pages (0-7)
    for (int col = 0; col < 128; col++) { // 128 columns per page
      Wire.beginTransmission(SCREEN_ADDR);
      Wire.write(0x40);  // Co = 0, D/C# = 1 (indicates data byte)
      Wire.write(byte);  // Write 0xFF to turn on all 8 pixels in this column
      Wire.endTransmission();
      //delay(10);
    }
  }
}

void initScreen(void) {
  // display off
  sendCommand(0xAE);
  // set MUX ratio 0x3F for 128x64 display
  sendCommand(0xA8);
  sendCommand(0x3F);
  // set display offset
  sendCommand(0xD3);
  sendCommand(0x00);
  // set isplay start line
  sendCommand(0x40);
  // set segment remap
  sendCommand(0xA1);  //a0
  // set com output scan direction
  sendCommand(0xC8);  //c0
  // set com pins hardwware config
  sendCommand(0xDA);
  sendCommand(0x12);
  // set contrast control
  sendCommand(0x81);
  sendCommand(0x7F);
  // isable entire display on
  sendCommand(0xA4);
  // set nrmal display
  sendCommand(0xA6);
  // set osc frequency
  sendCommand(0xD5);
  sendCommand(0x80);
  // enable charge pump regulator
  sendCommand(0x8D);
  sendCommand(0x14);
  // display on
  sendCommand(0xAF);



}