#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define USB_VID 0x303a
#define USB_PID 0x1001

// The default Wire will be mapped to PMU and RTC
static const uint8_t SDA = 13;
static const uint8_t SCL = 14;

// Default SPI is the LR1110 radio bus
static const uint8_t SS = 42;
static const uint8_t MOSI = 45;
static const uint8_t MISO = 46;
static const uint8_t SCK = 40;

#endif /* Pins_Arduino_h */
