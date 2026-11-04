# WS-ESP32-S3-LT1121-OLED-1.54
WIP Meshtastic support for Waveshare ESP32-S3-LR1121-OLED-1.54 


# Features

* Equipped with an ESP32-S3 dual-core Xtensa LX7 processor, 240 MHz clock speed, supporting 2.4 GHz Wi-Fi and BLE 5

* Features 16 MB Flash and 8 MB Octal PSRAM

* Onboard LR1121 LoRa wireless module, supporting LoRa and GFSK modulation, SPI interface

* Onboard 1.54inch OLED display (SSD1309, 128 × 64, I2C interface)

* Onboard ES7210 microphone ADC and ES8311 audio DAC, supporting voice capture and playback

* Onboard PCF85063A RTC, BQ27220 battery fuel gauge, TF/MMC card slot

* 4 function buttons (BOOT, PWR, MENU, PTT) and 1 reset button (RST); the walkie-talkie example provides Light Sleep and button wake-up functions


<img width="960" height="963" alt="image" src="https://github.com/user-attachments/assets/481bad58-e465-430b-bd1f-73e6f68c64c3" />

<img width="960" height="725" alt="image" src="https://github.com/user-attachments/assets/53cd34ce-01b5-4d47-ab8f-6ccf1322192d" />



| Feature | Status | Notes |
| :--- | :---: | :--- |
| **System Board ** |  | Meshtastic starts successfully. |
| **Firmware Flasing** |  | Working via USB-C |
| **Button** |  | Working |
| **UART** |  | Working |
| **Bluetooth** |  | Working |
| **LoRa Radio** |  | Working |
| **I2C OLED Display** |  | Working |
| RTC |  | Working I guess |
| BQ27220 |  | Working I guess my device have no battery |
| Speaker |  | Not yet |
| Microphone |  | Not yet |

---

Firmware Build notes
```
git clone --recurse-submodules https://github.com/meshtastic/firmware.git
git clone https://github.com/markbirss/WS-ESP32-S3-LR1121-OLED-1.54.git
cp WS-ESP32-S3-LR1121-OLED-1.54/boards/ESP32-S3-LR1121-OLED-1.54.json firmware/boards/
cp -r WS-ESP32-S3-LR1121-OLED-1.54/ESP32-S3-LR1121-OLED-1.54/ firmware/variants/esp32s3/
cd firmware/
pio run -e ESP32-S3-LR1121-OLED-154 -t upload
```

---

## Further Reading

https://www.waveshare.com/esp32-s3-lr1121-oled-1.54.htm?sku=35898

https://github.com/waveshareteam/esp32-s3-lr1121-oled-1.54/tree/main/examples/arduino

## ⚠️ Disclaimer

> [!WARNING]
> Use of the resources provided in this repository is entirely at your own risk. I take no responsibility for any hardware damage, malfunctions, or data loss.

---

## ☕ Support My Work

If this open-hardware project brings value to you, please consider supporting my design pipeline!

[![Buy Me A Coffee](https://img.shields.io/badge/buy_me_a_coffee-FFDD00?style=for-the-badge&logo=buy-me-a-coffee&logoColor=black)](https://buymeacoffee.com/mark.birss)
