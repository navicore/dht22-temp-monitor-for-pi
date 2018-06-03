#include <ctype.h>
#include <wiringPi.h>
#include "measure.h"

/**
 * based on code from https://github.com/ccoong7/DHT22.git
 */

/**
 *
 * read signal duration in microseconds
 *
 * 'signal' param is the gpio number, ie 4 or 23 or...
 *
 */
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

