#ifndef TCATMega328_h
#define TCATMega328_h

class TCATMega328 {
 public:
  TCATMega328();
  void init();
  void awake();
  void sleep();

  long readVcc();
  long readTemp();
};
#endif
