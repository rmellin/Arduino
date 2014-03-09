#include <avr/sleep.h>

#include "Arduino.h"
#include "TCATMega328.h"

TCATMega328::TCATMega328() {
}

void TCATMega328::init() {
	  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // sleep mode is set here
    	  sleep_enable();          // enables the sleep bit in the mcucr register
}

void TCATMega328::awake() {
    	  sleep_disable();         // first thing after waking from sleep:
}

void TCATMega328::sleep() {
    	  sleep_mode();            // here the device is actually put to sleep!!
    	  sleep_disable();         // first thing after waking from sleep:
}

long TCATMega328::readVcc() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1126400L / result; // Back-calculate AVcc in mV
  return result;
}

long TCATMega328::readTemp() {
  long result;
  // Read temperature sensor against 1.1V reference
  ADMUX = _BV(REFS1) | _BV(REFS0) | _BV(MUX3);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = (result - 125) * 1075;
  return result;
}
