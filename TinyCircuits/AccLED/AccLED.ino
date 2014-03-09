#include <Arduino.h>
#include <avr/sleep.h>
#include <Wire.h>

#include <TCAccelerometer.h>
#include <TCLEDShield.h>
#include <TCATMega328.h>

#define LIMIT	3*600
TCATMega328 theTCATMega;
TCAccelerometer theAccelerometer;
TCLEDShield theTCLEDShield;
int tick = 0;

void setup()
{
  Serial.begin(9600);
  theTCATMega.init();
  theAccelerometer.init();
  theTCLEDShield.init();
}


void loop()
{
	if( tick < LIMIT ) {
	    if( (tick % 10) == 0 ) { // checking every 10th tick, i.e. 10 * (15+15) ~ 300ms 
   	    	theAccelerometer.read();
  	    }
  	    tick++;
	    int ledPin = abs(theAccelerometer.getX()) / 16;
	    theTCLEDShield.ledOnFor(ledPin+1,15);
 	    ledPin = abs(theAccelerometer.getY()) / 16;
	    theTCLEDShield.ledOnFor(ledPin+1, 15);
        } else {
	  theTCLEDShield.sleep();
	  theAccelerometer.sleep();
	  theTCATMega.sleep();
	  theTCATMega.awake();
	  theAccelerometer.awake();
	  theTCLEDShield.awake();
        }
}


