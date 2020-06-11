/*

	In this example we'll blink a LED whenever the interrupt pin goes HIGH

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

	// Enable the interrupt
	LIS3DH_Micro::setClick(1, 6);

	digitalWrite(PIN_LED, LOW);

}

void loop(){

	// Blink when the "click" is detected
	if( digitalRead(PIN_INTERRUPT) ){

		digitalWrite(PIN_LED, HIGH);
		delay(200);
		digitalWrite(PIN_LED, LOW);

	}


}
