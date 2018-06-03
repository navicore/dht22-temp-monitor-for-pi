#include <jni.h>
#include "onextent_iot_dht22_Dht22.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <wiringPi.h>
#include "readData.h"

/**
 * based on code from https://github.com/ccoong7/DHT22.git
 */

/**
 *
 * get Celsius, Fahrenheit, and humidity in a float array
 *
 * if values are !> 0, retry
 *
 */
JNIEXPORT jfloatArray JNICALL Java_onextent_iot_dht22_Dht22_get
(JNIEnv * env, jobject obj, jint signal) {

  jfloatArray ret = env->NewFloatArray(3);

	float humidity;
	float celsius;
	float fahrenheit;
	short checksum;
  unsigned short data[5] = {0, 0, 0, 0, 0};

	// GPIO Initialization
	if (wiringPiSetupGpio() == -1) {
		printf("GPIO Initialization FAILED\n");
		return ret;
	}

  pinMode(signal, OUTPUT);

  // Send out start signal
  digitalWrite(signal, LOW);
  delay(20);					// Stay LOW for 5~30 milliseconds
  pinMode(signal, INPUT);		// 'INPUT' equals 'HIGH' level. And signal read mode

  readData(signal, data);		// Read DHT22 signal

  // The sum is maybe over 8 bit like this: '0001 0101 1010'.
  // Remove the '9 bit' data using AND operator.
  checksum = (data[0] + data[1] + data[2] + data[3]) & 0xFF;
  
  // If Check-sum data is correct (NOT 0x00), display humidity and temperature
  if (data[4] == checksum && checksum != 0x00) {
    // * 256 is the same thing '<< 8' (shift).
    humidity = ((data[0] * 256) + data[1]) / 10.0;
    celsius = data[3] / 10.0;

    // If 'data[2]' data like 1000 0000, It means minus temperature
    if (data[2] == 0x80) {
      celsius *= -1;
    }

    fahrenheit = ((celsius * 9) / 5) + 32;

    float arr[3]={celsius,fahrenheit,humidity}; //set results
    env->SetFloatArrayRegion(ret,0,3,arr);
  
  }

	return ret;
}
