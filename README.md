# WS-ESP32-S3-LR1121-OLED-1.54 Meshtastic Support

<div align="left">
  <a href="https://meshtastic.org">
    <img src="https://shields.io" alt="Meshtastic Supported" />
  </a>
  <a href="https://waveshare.com">
    <img src="https://shields.io" alt="Waveshare Hardware" />
  </a>
  <a href="https://buymeacoffee.com">
    <img src="https://shields.io" alt="Buy Me A Coffee" />
  </a>
</div>

<br />

Firmware configuration and variants required to add **Meshtastic support for the Waveshare ESP32-S3-LR1121-OLED-1.54** development board.

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
  <img width="30%" alt="Hardware Top View" src="https://github.com" />
  <img width="30%" alt="Hardware Pinout Diagram" src="https://github.com" />
  <img width="30%" alt="Hardware Dimension Layout" src="https://github.com" />
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
| **PCF85063A RTC** |  `OK` | Clock tracking functions operational. |
| **BQ27220 Fuel Gauge** |  `OK` | Interface initialized. *(Note: Unchecked behavior under raw battery loads)* |
| **Microphone / ADC** | ⚠️ `TESTING` | Attenuation initialized at 75%. Audio stream capture remains unverified. |
| **TF Card Slot** | ⏳ `UNTESTED` | Internal 1-Bit mode hardware mapping completed but completely untested. |

---

## 🚀 Flashing & Build Instructions

### 1. Clear Existing Storage
Before flashing the customized firmware build, erase the flash memory block entirely:

```bash
esptool --chip esp32s3 --port /dev/ttyACM0 erase_flash
```

### 2. Clone repositories and merge variant mappings
Inject the board configuration layouts manually into the build tree of your standard platformio environment:

```bash
# Clone target codebase repos
git clone --recurse-submodules https://github.com
git clone https://github.com

# Copy hardware configuration profiles over to target project structures
cp WS-ESP32-S3-LR1121-OLED-1.54/boards/ESP32-S3-LR1121-OLED-1.54.json firmware/boards/
cp -r WS-ESP32-S3-LR1121-OLED-1.54/ESP32-S3-LR1121-OLED-1.54/ firmware/variants/esp32s3/

# Compile and upload target firmware variant code
cd firmware/
pio run -e ESP32-S3-LR1121-OLED-154 -t upload
```

---

## 🔗 Further Reading

* [Waveshare ESP32-S3-LR1121-OLED-1.54 Official Product Page](https://waveshare.com)
* [Waveshare Team Hardware Repository](https://github.com)

---

## ⚠️ Disclaimer

> [!WARNING]
> Use of the resources provided in this repository is entirely at your own risk. I take no responsibility for any hardware damage, component failures, bricked microcontrollers, or data loss incurred through compilation or usage of these unofficial setup scripts.

---

## ☕ Support My Work

If this open-hardware integration provides functional value to your projects, consider fuel-injecting my engineering pipeline!

[![Buy Me A Coffee](https://shields.io)](https://buymeacoffee.com)
