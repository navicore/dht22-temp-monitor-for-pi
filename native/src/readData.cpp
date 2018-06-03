#include <ctype.h>
#include <wiringPi.h>
#include "measure.h"
#include "readData.h"

short readData(short signal, short unsigned *data) {

	unsigned short val = 0x00;
	unsigned short signal_length = 0;
	unsigned short val_counter = 0;
	unsigned short loop_counter = 0;
	
	while (1) {

    signal_length = measure(signal);

		// If signal is HIGH
		if (signal_length > 0) {
			loop_counter++;	// HIGH signal counting

			// The DHT22 sends a lot of unstable signals.
			// So extended the counting range.
			if (signal_length < 10) {
				// Unstable signal
				val <<= 1;		// 0 bit. Just shift left
			}

			else if (signal_length < 30) {
				// 26~28us means 0 bit
				val <<= 1;		// 0 bit. Just shift left
			}

			else if (signal_length < 85) {
				// 70us means 1 bit	
				// Shift left and input 0x01 using OR operator
				val <<= 1;
				val |= 1;
			} else {
				// Unstable signal
				return -1;
			}

			signal_length = 0;	// Initialize signal length for next signal
			val_counter++;		// Count for 8 bit data
		}

		// The first and second signal is DHT22's start signal.
		// So ignore these data.
		if (loop_counter < 3) {
			val = 0x00;
			val_counter = 0;
		}

		// If 8 bit data input complete
		if (val_counter >= 8) {
			// 8 bit data input to the data array
			data[(loop_counter / 8) - 1] = val;
			
      val = 0x00;
			val_counter = 0;
		}
	}

}

