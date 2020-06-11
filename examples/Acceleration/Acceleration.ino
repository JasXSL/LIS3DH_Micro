/*

	Todo: This one hasn't been fully tested yet
	Need to test this with something that can serial print.

*/
#include "ExampleConfig.h"	// Config allows us to set the compile time settings
#include <LIS3DH_Micro.h>	// Include the library


const uint8_t PIN_LED = 4;			// LED 
const uint8_t PIN_INTERRUPT = 0;	// Interrupt input

void setup(){


	pinMode(PIN_LED, OUTPUT);
	digitalWrite(PIN_LED, LOW);

	pinMode(PIN_INTERRUPT, INPUT);
	
	// Try both addresses. If the circuit ends up blinking bright and low bright, it means you have a hardware error.
	bool on = false;
  	while( !LIS3DH_Micro::begin(on ? 0x19 : LIS3DH_DEFAULT_ADDRESS) ) {   // change this to 0x19 for alternative i2c address
		analogWrite(PIN_LED, on ? 5 : 20);
		on = !on;
		delay(1000);
  	}

	digitalWrite(PIN_LED, LOW);

}

void loop(){

	// Blink when the "click" is detected
	// read from the accelerometer

	LIS3DH_Micro::read();

	uint32_t acceleration = abs(LIS3DH_Micro::x)+abs(LIS3DH_Micro::y)+abs(LIS3DH_Micro::z);
	acceleration = min(acceleration, 16000*3);	// 16g max on each axis

	analogWrite(PIN_LED, map(acceleration, 0, 16000*3, 0, 1024));	// Set LED brightness based on acceleration detected. Keep in mind gravity is included.

	delay(33);


}
