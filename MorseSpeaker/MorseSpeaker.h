#ifndef MorseEnDecoder_H
#define MorseEnDecoder_H

#include <Arduino.h>
#include "pitches.h"

#define OUTPUT_TONE_PITCH NOTE_A3
#define SIDE_TONE_PITCH NOTE_C4


class MorseSpeaker
{
  public:
    MorseSpeaker(int t_spkrPin);
    void outputTone(boolean t_on);
    void sideTone(boolean t_on);
    boolean outputToneOn;
    boolean sideToneOn;
  private:
    boolean keyDown;
  protected:
    int spkrOut;
};

#endif
