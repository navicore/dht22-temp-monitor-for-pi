#include <ctype.h>
#include <wiringPi.h>
#include "measure.h"

short measure(short signal) {
  unsigned short signal_length = 0;
  // Count only HIGH signal
  while (digitalRead(signal) == HIGH) {
    signal_length++;
    // When sending data ends, high signal occur infinite.
    // So we have to end this infinite loop.
    if (signal_length >= 200) {
      return -1;
    }
    delayMicroseconds(1);
  }
  return signal_length;
}

