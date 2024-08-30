/*
  Fur Elise
  Connect a piezo buzzer or speaker to pin 11 or select a new pin.
  More songs available at https://github.com/robsoncouto/arduino-songs

                                              Robson Couto, 2019
*/

/*

Original Sketch by Robson Couto 2019
https://github.com/robsoncouto/arduino-songs and Converted for use with the
M5Stack Core Ink by LeRoy Miller in Jan 2021

Mar 12, 2024 modified by LeRoy Miller for use with the M5StickC and the Synth
Midi Unit
 -> Changed note definitions to values that will work with the Synth Midi Unit
 -> Changed tone/notone to setNoteOn and setNoteOff
 -> added the M5UnitMIDI library
 -> added a variable to change the instrument used

*/

#include <M5Stack.h>
#include <M5_SAM2695.h>
#include "melody.h"

M5_SAM2695 midi;

// change this to make the song slower or faster
int tempo = 80;
// sizeof gives the number of bytes, each int value is composed of two bytes (16
// bits) there are two values per note (pitch and duration), so for each note
// there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void play() {
    // iterate over the notes of the melody.
    // Remember, the array is twice the number of notes (notes + durations)
    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
        // calculates the duration of each note
        divider = melody[thisNote + 1];
        if (divider > 0) {
            // regular note, just proceed
            noteDuration = (wholenote) / divider;
        } else if (divider < 0) {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5;  // increases the duration in half for dotted notes
        }

        // we only play the note for 90% of the duration, leaving 10% as a pause
        midi.setNoteOn(0, melody[thisNote], 127);  // noteDuration * 0.9);
        // Wait for the specief duration before playing the next note.
        delay(noteDuration);
        // stop the waveform generation before the next note.
        midi.setNoteOff(0, melody[thisNote], 127);
    }
}

void setup() {
    M5.begin(true, false, true, false);
    Serial.println("MIDI FurElise");
    M5.Lcd.setTextColor(YELLOW);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setCursor(80, 10);
    M5.Lcd.println("MIDI FurElise");
    midi.begin(&Serial2, MIDI_BAUD, 16, 17);
    midi.setInstrument(0, 0, ElGrdPiano_3);  // synth piano 1
    M5.Lcd.setCursor(50, 85);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.println("Generating audio....");
    play();
}

void loop() {
    // no need to repeat the melody.
}
