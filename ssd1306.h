#ifndef SSD1306_HPP
#define SSD1306_HPP

#include <Arduino.h>
#include <Wire.h>

#define SCREEN_ADDR 0x3C


void initScreen(void);
void fillScreen(uint8_t byte);
void sendCommand(uint8_t command);
void allScreen(uint8_t byte);


#endif