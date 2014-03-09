#ifndef TCLEDShield_h
#define TCLEDShield_h

class TCLEDShield {

public:
  TCLEDShield();

  void init();
  void awake();
  void sleep();

  void ledOn(int ledNo);
  void ledOnFor(int ledNo, int millis);
  void ledOff();

};

#endif
