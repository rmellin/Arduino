#include "Arduino.h"

#include "TCLEDShield.h"

  TCLEDShield::TCLEDShield() {
  }

  void TCLEDShield::init() {
    pinMode(5, INPUT);  
    pinMode(6, INPUT);  
    pinMode(7, INPUT);  
    pinMode(8, INPUT);  
    pinMode(9, INPUT);  
  }

void TCLEDShield::awake() {
  init();
}

void TCLEDShield::sleep() {
  init();
}

void TCLEDShield::ledOff() {
  init();
}

void TCLEDShield::ledOn(int iLedNum) {
   if( iLedNum == 1 ) {
      digitalWrite( 5, HIGH );
      digitalWrite( 6, LOW );
     
      pinMode(5, OUTPUT);  
      pinMode(6, OUTPUT);  
      pinMode(7, INPUT);  
      pinMode(8, INPUT);  
      pinMode(9, INPUT);        
   } else if( iLedNum == 2 ) {
      digitalWrite( 5, LOW );
      digitalWrite( 6, HIGH );
     
      pinMode(5, OUTPUT);  
      pinMode(6, OUTPUT);  
      pinMode(7, INPUT);  
      pinMode(8, INPUT);  
      pinMode(9, INPUT);        
   }  else if( iLedNum == 3 ) {
      digitalWrite( 5, HIGH );
      digitalWrite( 7, LOW );
     
      pinMode(5, OUTPUT);  
      pinMode(6, INPUT);  
      pinMode(7, OUTPUT);  
      pinMode(8, INPUT);  
      pinMode(9, INPUT);        
   }  else if( iLedNum == 4 ) {
      digitalWrite( 7, HIGH );
      digitalWrite( 5, LOW );
     
      pinMode(5, OUTPUT);  
      pinMode(6, INPUT);  
      pinMode(7, OUTPUT);  
      pinMode(8, INPUT);  
      pinMode(9, INPUT);        
   } else if( iLedNum == 5 ) {
      digitalWrite( 6, HIGH );
      digitalWrite( 7, LOW );
     
      pinMode(5, INPUT);  
      pinMode(6, OUTPUT);  
      pinMode(7, OUTPUT);  
      pinMode(8, INPUT);  
      pinMode(9, INPUT);        
   } else if( iLedNum == 6 ) {
      digitalWrite( 7, HIGH );
      digitalWrite( 6, LOW );
     
      pinMode(5, INPUT);  
      pinMode(6, OUTPUT);  
      pinMode(7, OUTPUT);  
      pinMode(8, INPUT);  
      pinMode(9, INPUT);        
   } else if( iLedNum == 7 ) {
      digitalWrite( 6, HIGH );
      digitalWrite( 8, LOW );
     
      pinMode(5, INPUT);  
      pinMode(6, OUTPUT);  
      pinMode(7, INPUT);  
      pinMode(8, OUTPUT);  
      pinMode(9, INPUT);        
   } else if( iLedNum == 8 ) {
      digitalWrite( 8, HIGH );
      digitalWrite( 6, LOW );
     
      pinMode(5, INPUT);  
      pinMode(6, OUTPUT);  
      pinMode(7, INPUT);  
      pinMode(8, OUTPUT);  
      pinMode(9, INPUT);        
   } else if( iLedNum == 9 ) {
      digitalWrite( 5, HIGH );
      digitalWrite( 8, LOW );
     
      pinMode(5, OUTPUT);  
      pinMode(6, INPUT);  
      pinMode(7, INPUT);  
      pinMode(8, OUTPUT);  
      pinMode(9, INPUT);        
   } else if( iLedNum == 10 ) {
      digitalWrite( 8, HIGH );
      digitalWrite( 5, LOW );
     
      pinMode(5, OUTPUT);  
      pinMode(6, INPUT);  
      pinMode(7, INPUT);  
      pinMode(8, OUTPUT);  
      pinMode(9, INPUT);        
   } else if( iLedNum == 11 ) {
      digitalWrite( 8, HIGH );
      digitalWrite( 7, LOW );
     
      pinMode(5, INPUT);  
      pinMode(6, INPUT);  
      pinMode(7, OUTPUT);  
      pinMode(8, OUTPUT);  
      pinMode(9, INPUT);        
   }  else if( iLedNum == 12 ) {
      digitalWrite( 7, HIGH );
      digitalWrite( 8, LOW );
     
      pinMode(5, INPUT);  
      pinMode(6, INPUT);  
      pinMode(7, OUTPUT);  
      pinMode(8, OUTPUT);  
      pinMode(9, INPUT);        
   } else if( iLedNum == 13 ) {
      digitalWrite( 9, HIGH );
      digitalWrite( 7, LOW );
     
      pinMode(5, INPUT);  
      pinMode(6, INPUT);  
      pinMode(7, OUTPUT);  
      pinMode(8, INPUT);  
      pinMode(9, OUTPUT);        
   } else if( iLedNum == 14 ) {
      digitalWrite( 7, HIGH );
      digitalWrite( 9, LOW );
     
      pinMode(5, INPUT);  
      pinMode(6, INPUT);  
      pinMode(7, OUTPUT);  
      pinMode(8, INPUT);  
      pinMode(9, OUTPUT);        
   } else if( iLedNum == 15 ) {
      digitalWrite( 9, HIGH );
      digitalWrite( 8, LOW );
     
      pinMode(5, INPUT);  
      pinMode(6, INPUT);  
      pinMode(7, INPUT);  
      pinMode(8, OUTPUT);  
      pinMode(9, OUTPUT);        
   } else if( iLedNum == 16 ) {
      digitalWrite( 8, HIGH );
      digitalWrite( 9, LOW );
     
      pinMode(5, INPUT);  
      pinMode(6, INPUT);  
      pinMode(7, INPUT);  
      pinMode(8, OUTPUT);  
      pinMode(9, OUTPUT);        
   }
  }

void TCLEDShield::ledOnFor(int ledNo, int millis) {
    ledOn(ledNo);
    delay(millis);
  }

