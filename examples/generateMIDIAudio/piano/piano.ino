/*
 * SPDX-FileCopyrightText: 2024 M5Stack Technology CO LTD
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * @file piano.ino
 * @brief MIDI Piano Example
 * @version 0.1
 * @date 2024-07-17
 *
 * @Hardwares: M5Core + Unit Synth
 *         or  M5Core + Unit MIDI(Need to connect speakers/headphones)
 * @Platform Version: Arduino M5Stack Board Manager v2.1.0
 * @Dependent Library:
 * M5_SAM2695: https://github.com/m5stack/M5-SAM2695
 */

#include <M5Stack.h>
#include "M5_SAM2695.h"

M5_SAM2695 midi;

void setup() {
    M5.begin(true, false, true, false);
    Serial.println("MIDI Piano");
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(100, 10);
    M5.Lcd.println("MIDI Piano");
    M5.Lcd.setCursor(120, 35);
    M5.Lcd.setTextColor(BLUE);
    M5.Lcd.println("MASTER");
    midi.begin(&Serial2, MIDI_BAUD, 16, 17);
    midi.setInstrument(0, 0, GrandPiano_1);  // midi piano 1
    M5.Lcd.setCursor(50, 85);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.println("Generating audio....");
}

void loop() {
    midi.setNoteOn(0, NOTE_C4, 127);
    delay(1000);
    midi.setNoteOn(0, NOTE_D4, 127);
    delay(1000);
    midi.setNoteOn(0, NOTE_E4, 127);
    delay(1000);
    midi.setNoteOn(0, NOTE_F4, 127);
    delay(1000);
    midi.setNoteOn(0, NOTE_G4, 127);
    delay(1000);
    midi.setNoteOn(0, NOTE_A4, 127);
    delay(1000);
    midi.setNoteOn(0, NOTE_B4, 127);
    delay(1000);
    midi.setNoteOn(0, NOTE_C5, 127);
    delay(1000);
}
