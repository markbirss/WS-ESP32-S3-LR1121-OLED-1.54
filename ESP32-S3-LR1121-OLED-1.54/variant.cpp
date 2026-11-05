#include "variant.h"
#include <Arduino.h>
#include <AudioBoard.h>
#include <Wire.h>

// --- Hardware-Specific Gain Parameters ---
// Hardware scaling factor matching a 3.3V to 5.0V voltage step-down translation
static constexpr float AUDIO_ES8311_HW_GAIN_DB = -3.6f;

// The driver expects a percentage (0-100) instead of a raw register value.
// Let's set an input volume percentage (e.g., 75%) that maps to your desired mic boost.
static constexpr uint8_t AUDIO_MIC_INPUT_VOLUME_PCT = 75;

DriverPins PinsAudioBoardES8311;
AudioBoard board(AudioDriverES8311, PinsAudioBoardES8311);

void lateInitVariant() {
  // 1. Establish the register communication path
  Wire.begin(I2C_SDA, I2C_SCL);
  PinsAudioBoardES8311.addI2C(PinFunction::CODEC, Wire);

  // 2. Set up parameter constraints for this specific board
  CodecConfig cfg;
  cfg.input_device = ADC_INPUT_LINE1;
  cfg.output_device = DAC_OUTPUT_ALL;
  cfg.i2s.bits = BIT_LENGTH_16BITS;
  cfg.i2s.rate = RATE_48K;
  cfg.i2s.fmt = I2S_NORMAL;

  // 3. Initialize register table with safety validation
  if (board.begin(cfg)) {
    Serial.println("[Variant Setup] ES8311 Hardware registers initialized successfully.");

    // Apply the fixed hardware attenuation factor into your primary output volume map
    float baselineVolume = 95.0f * pow(10.0f, AUDIO_ES8311_HW_GAIN_DB / 20.0f);
    board.setVolume(static_cast<uint8_t>(baselineVolume));

    // 4. FIX: Use setInputVolume with a 0-100% parameter
    board.setInputVolume(AUDIO_MIC_INPUT_VOLUME_PCT);

    // 5. Safely un-mute now that registers reflect proper scaling
    pinMode(PA_CTRL, OUTPUT);
    digitalWrite(PA_CTRL, HIGH);
    board.setMute(false);

  } else {
    Serial.println("[Variant Setup] ES8311 Hardware registry communication failed!");
  }
}
