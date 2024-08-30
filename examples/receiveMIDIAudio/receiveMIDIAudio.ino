/*
 * SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * @file receiveMIDIAudio.ino
 * @brief Unit MIDI receives MIDI signals
 * @version 0.1
 * @date 2024-07-17
 *
 * @Hardwares: M5Core + Unit MIDI(Need to connect speakers/headphones)
 * @Platform Version: Arduino M5Stack Board Manager v2.1.0
 * @Dependent Library:
 * M5_SAM2695: https://github.com/m5stack/M5_SAM2695
 *
 * @Usage: For specific usage, please see README
 */

#include <M5Stack.h>
#include "M5_SAM2695.h"

M5_SAM2695 midi;

uint16_t cnt = 0;

void setup() {
    M5.begin(true, false, true, false);
    Serial.println("Receives MIDI signals");
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(80, 10);
    M5.Lcd.println("Receives MIDI signals");
    // midi.begin(&Serial2, MIDI_BAUD, 16, 17);
    // midi.setInstrument(0, 9, SynthDrum);  // synth drum
    M5.Lcd.setCursor(0, 55);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.print("Receiving");
}

void loop() {
    if (Serial2.available()) {
        byte midiData = Serial2.read();
        Serial2.write(midiData);
        Serial.print(midiData);
        M5.Lcd.print(".");
        if (++cnt > 260) {
            cnt = 0;
            M5.Lcd.fillRect(0, 55, 320, 240, BLACK);
            M5.Lcd.setCursor(0, 55);
            M5.Lcd.print("Receiving");
        }
    }
}