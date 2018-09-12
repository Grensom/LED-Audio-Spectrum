Please Read these instructions for setting up the LED-Audio_Spectrum Project
----------------------------------------------------------
STEP 1: Download the needed Libraries
----------------------------------------------------------
You will need the following libraries:
FastLED.h
LiquidCrystal.h (optional)

You can get these by going to Arduino IDE >> Sketch >> Include Library >> Manage Libraries >> "search for" FastLED and install library

----------------------------------------------------------
STEP 2: Choose the Appropriate File to Upload to Arduino
----------------------------------------------------------
1. Led_audio.ino
- this file simply takes audio input from Sound Detector Module and converts it into colored spectrum on LED Strip

2. Led_audio_cycle.ino
- this file has audio spectrum, manual cycle and auto cycle built into it with main potentiometer(see below)

3. Led_audio_cycle_bright_sens.ino
- this file has audio spectrum, manual cycle and auto cycle built into it with main potentiometer(see below) plus allows you to adjust brightness and sensitivity of audio sensor with another two potentiometers

4. Led_audio_cycle_bright_sens_display.ino
- this is the same as #3 but the brightness and sensitivity is displayed on a 16x2 LED Display (requires the LiquidCrystal.h library)

----------------------------------------------------------
STEP 3: 
----------------------------------------------------------
