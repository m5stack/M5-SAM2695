/*
 * SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * @file drum.ino
 * @brief MIDI Drum Example
 * @version 0.1
 * @date 2024-07-17
 *
 * @Hardwares: M5Core + Unit Synth
 *         or  M5Core + Unit MIDI(Need to connect speakers/headphones)
 * @Platform Version: Arduino M5Stack Board Manager v2.1.0
 * @Dependent Library:
 * M5_SAM2695: https://github.com/m5stack/M5_SAM2695
 */

#include <M5Stack.h>
#include "M5_SAM2695.h"

M5_SAM2695 midi;

void setup() {
    M5.begin(true, false, true, false);
    Serial.println("MIDI Drum");
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(100, 10);
    M5.Lcd.println("MIDI Drum");
    midi.begin(&Serial2, MIDI_BAUD, 16, 17);
    midi.setInstrument(0, 9, SynthDrum);  // synth drum
    M5.Lcd.setCursor(50, 85);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.println("Generating audio....");
}

void loop() {
    midi.setNoteOn(9, 36, 127);
    midi.setNoteOn(9, 42, 127);
    delay(300);
    midi.setNoteOn(9, 42, 127);
    delay(300);
    midi.setNoteOn(9, 38, 127);
    midi.setNoteOn(9, 42, 127);
    delay(300);
    midi.setNoteOn(9, 42, 127);
    delay(300);

    midi.setNoteOn(9, 36, 127);
    midi.setNoteOn(9, 42, 127);
    delay(300);
    midi.setNoteOn(9, 36, 127);
    midi.setNoteOn(9, 42, 127);
    delay(300);
    midi.setNoteOn(9, 38, 127);
    midi.setNoteOn(9, 42, 127);
    delay(300);
    midi.setNoteOn(9, 42, 127);
    delay(300);
}
