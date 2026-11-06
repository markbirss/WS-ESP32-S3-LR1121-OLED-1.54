# WS-ESP32-S3-LR1121-OLED-1.54 Meshtastic Support

Meshtastic Firmware variant for the Waveshare **ESP32-S3-LR1121-OLED-1.54**

---

## 🛠️ Hardware Features

* **Core Processor:** ESP32-S3 dual-core Xtensa LX7 processor running at 240 MHz. Supports 2.4 GHz Wi-Fi and BLE 5.
* **Memory Configuration:** Onboard 16 MB Flash and 8 MB Octal PSRAM.
* **LoRa Module:** Onboard LR1121 LoRa wireless module supporting LoRa and GFSK modulation via SPI interface.
* **Display:** Onboard 1.54-inch OLED display (SSD1309 controller, 128 × 64 resolution, I2C interface).
* **Audio Capabilities:** Onboard ES7210 microphone ADC and ES8311 audio DAC supporting voice capture and playback.
* **Peripherals:** Onboard PCF85063A RTC, BQ27220 battery fuel gauge, and an integrated TF/MMC card slot.
* **User Interfaces:** 4 function buttons (`BOOT`, `PWR`, `MENU`, `PTT`) and 1 reset button (`RST`). The default walkie-talkie firmware profile provides Light Sleep and button wake-up routines.

---

## 📸 Media / Preview

<p align="center">
  <img width="30%" alt="Hardware Top View" src="https://github.com/user-attachments/assets/481bad58-e465-430b-bd1f-73e6f68c64c3" />
  <img width="30%" alt="Hardware Pinout Diagram" src="https://github.com/user-attachments/assets/53cd34ce-01b5-4d47-ab8f-6ccf1322192d" />
  <img width="30%" alt="Hardware Dimension Layout" src="https://github.com/user-attachments/assets/ee6b18ce-f9b3-447b-82b6-34d4014d50b0" />
</p>

---

## 📊 Meshtastic Feature Matrix

| Feature | Status | Notes |
| :--- | :---: | :--- |
| **System Board** |  `OK` | Meshtastic target boots and initializes successfully. |
| **Firmware Flashing** |  `OK` | Fully operational via native USB-C CDC interface. |
| **Menu Button** |  `OK` | Functional. |
| **Power Button** |  `OK` | Functional. Hold down for 5 seconds to toggle system power state. |
| **UART Hardware** |  `OK` | Validated and functional. |
| **Bluetooth (BLE)** |  `OK` | Validated and functional. |
| **LoRa Radio** |  `OK` | RF paths and chip communication verified. |
| **I2C OLED Display** |  `OK` | Screen turns on and UI renders correctly. |
| **Speaker / Audio DAC** |  `OK` | Functional. Software attenuation set at 85%. |
| **PCF85063A RTC** |  `OK` | Seems operational. |
| **BQ27220 Fuel Gauge** |  `OK` | Interface initialized. *(Note: Unchecked as my device have no battery installed)* |
| **Microphone / ADC** | ⚠️ `TESTING` | Attenuation initialized at 75%. Audio stream capture remains unverified. |
| **TF Card Slot** | ⏳ `UNTESTED` | Internal 1-Bit mode hardware. |

---

## 🚀 Flashing & Build Instructions

### 1. Clear Existing Flash Storage
Before flashing the customized firmware build, erase the flash storage:

```bash
esptool --chip esp32s3 --port /dev/ttyACM0 erase_flash
```

### 2. Clone repositories and merge variant
Inject the board configuration layouts manually into the build tree of your standard platformio environment:

```bash
# Clone target codebase repos
git clone --recurse-submodules https://github.com/meshtastic/firmware.git
git clone https://github.com/markbirss/WS-ESP32-S3-LR1121-OLED-1.54

# Copy hardware configuration profiles over to target project structures
cp WS-ESP32-S3-LR1121-OLED-1.54/boards/ESP32-S3-LR1121-OLED-1.54.json firmware/boards/
cp -r WS-ESP32-S3-LR1121-OLED-1.54/ESP32-S3-LR1121-OLED-1.54/ firmware/variants/esp32s3/

# Compile and upload target firmware variant code
cd firmware/
pio run -e ESP32-S3-LR1121-OLED-154 -t upload

# Setup Nokia Phone TringTring RingTone
meshtastic --set-ringtone "TringTringLong:d=8,o=6,b=500:d,e,d,e,d,e,p,p,d,e,d,e,d,e,2p,1p,d,e,d,e,d,e,p,p,d,e,d,e,d,e,2p"

# Disable the UI button click sound
meshtastic --set device.buzzer_mode NOTIFICATIONS_ONLY
```

---

## 🔗 Further Reading

* https://www.waveshare.com/esp32-s3-lr1121-oled-1.54.htm
* https://github.com/waveshareteam/esp32-s3-lr1121-oled-1.54

---

## ⚠️ Disclaimer

> [!WARNING]
> Use of the resources provided in this repository is entirely at your own risk. I take no responsibility for any hardware damage, component failures, bricked microcontrollers, or data loss incurred through compilation or usage of these unofficial setup scripts.

---

## ☕ Support My Work

If this open-hardware integration provides functional value to your projects, consider fuel-injecting my engineering pipeline!

[![Buy Me A Coffee](https://img.shields.io/badge/buy_me_a_coffee-FFDD00?style=for-the-badge&logo=buy-me-a-coffee&logoColor=black)](https://buymeacoffee.com/mark.birss)
