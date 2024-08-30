# MIDI Unit Setup Guide

## Hardware Requirements
1. Core series mainframe * 2
2. Base M5GO BOTTOM base * 2
3. Grove cable * 2
4. Unit-MIDI * 2
5. MIDI male-to-male cable * 2 / 3.5mm stereo male-to-male cable * 2

<img src="https://static-cdn.m5stack.com/resource/docs/products/unit/Unit-MIDI/Unit_Midi_Guide_1.webp" alt="basic" width="500" height="350">

## Connection Instructions
1. Insert the BOTTOM base into the Core mainframe.
2. Connect Unit-MIDI to the BOTTOM base's blue Grove port using the Grove cable.
3. Flash the `generateMIDIAudio` example program onto one Core mainframe and the `receiveMIDIAudio` example program onto the other.
4. Connect the two Unit-MIDI devices using the MIDI male-to-male cable:
    - For the MASTER Unit-MIDI, connect the MIDI cable to the left output port.
    - For the SLAVE Unit-MIDI, connect the MIDI cable to the right input port.
5. Connect a headphone to the SLAVE Unit-MIDI.

**Note:**
- For the MASTER Unit-MIDI, set the DIP switch to "from core."
- For the SLAVE Unit-MIDI, set the DIP switch to "bypass."

<img src="https://static-cdn.m5stack.com/resource/docs/products/unit/Unit-MIDI/Unit_Midi_Guide_2.webp" alt="basic" width="500" height="350">


## Device Initialization
1. Power on the mainframe to start the device initialization of UART and Unit-MIDI.
    - Recommended: Power on the device with the `generateMIDIAudio` program first. When the screen displays "Generating audio," then power on the device with the `receiveMIDIAudio` program.

## Expected Results

If the SLAVE receives data, the screen on the SLAVE host will display `Receiving` followed by "..." continuously. The audio will be output through the headphones connected to the SLAVE-MIDI.

<img src="https://static-cdn.m5stack.com/resource/docs/products/unit/Unit-MIDI/Unit_Midi_Guide_3.webp" alt="basic" width="500" height="350">
