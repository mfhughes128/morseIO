/*
  Morse Speaker Class
    Generates audible output for encoder and sidetone for
    decoder. Sidetone over-rides output.
*/

#include "MorseSpeaker.h"


MorseSpeaker::MorseSpeaker(int t_spkrPin)
{
  // Setup the speaker output pin
  spkrOut = t_spkrPin;
  pinMode(spkrOut, OUTPUT);
  digitalWrite(spkrOut, LOW);

  // Set initial state
  keyDown = false;
  sideToneOn = false;
  outputToneOn = false;
  
  noTone(spkrOut);
}

void MorseSpeaker::outputTone(boolean t_on)
{
  if (outputToneOn) {
    if (t_on && !keyDown) {
      tone(spkrOut, OUTPUT_TONE_PITCH);
    } else {
      noTone(spkrOut);
    }
  }
}

void MorseSpeaker::sideTone(boolean t_on)
{
  if (sideToneOn) {
    if (t_on) {
      keyDown = true;
      tone(spkrOut, SIDE_TONE_PITCH);
    } else {
      keyDown = false;
      noTone(spkrOut);
    }
  }
}
