//https://docs.waveshare.com/ESP32-S3-LR1121-OLED-1.54
//https://www.waveshare.com/esp32-s3-lr1121-oled-1.54.htm
#define HAS_GPS 0
#define HAS_WIRE 1
#define HAS_SCREEN 1
#define I2C_NO_RESCAN

#define LED_PIN 2 // Used External for now
#define LED_STATE_ON 0
#define LED_STATE_OFF 1
#define BUTTON_PIN 5 // MENU Button
#define BUTTON_ACTIVE_LOW true
#define BUTTON_ACTIVE_PULLUP true

// Button GPIOs
#define PIN_KEY_BOOT 0
#define PIN_KEY_PWR  4
#define PIN_KEY_MENU 5
#define PIN_KEY_PTT  6

#define I2C_SDA SDA
#define I2C_SCL SCL
#define USE_SSD1306

// audio codec ES8311
#define AUDIO_AMP_SETTLE_MS 250
#define AUDIO_AMP_ENABLE(on)
#define HAS_I2S

#define PA_CTRL 8
#define DAC_I2S_BCK 18
#define DAC_I2S_WS 21
#define DAC_I2S_DOUT 16
#define DAC_I2S_DIN 15
#define DAC_I2S_MCLK 17

//#define HAS_DRV2605 1

// PCF85063 RTC Module
//#define PCF85063_RTC 0x51

// battery quality management BQ27220
#define HAS_BQ27220 1
#define BQ27220_I2C_SDA SDA
#define BQ27220_I2C_SCL SCL
#define BQ27220_DESIGN_CAPACITY 1500

#define UART_TX 43
#define UART_RX 44

#define LORA_SCK 40
#define LORA_MISO 46
#define LORA_MOSI 45
#define LORA_CS 42
#define LORA_RESET 39

#define LORA_DIO0 -1 // a No connect on the SX1262 module
#define LORA_DIO1 38 // SX1262 IRQ
#define LORA_DIO2 41 // SX1262 BUSY
#define LORA_DIO3

#define USE_LR1121
#define LR1121_IRQ_PIN LORA_DIO1
#define LR1121_NRESET_PIN LORA_RESET
#define LR1121_BUSY_PIN LORA_DIO2
#define LR1121_SPI_NSS_PIN LORA_CS
#define LR1121_SPI_SCK_PIN LORA_SCK
#define LR1121_SPI_MOSI_PIN LORA_MOSI
#define LR1121_SPI_MISO_PIN LORA_MISO
#define LR11X0_DIO3_TCXO_VOLTAGE 1.8
#define LR11X0_DIO_AS_RF_SWITCH
