#ifndef TCAccelerometer_h
#define TCAccelerometer_h

class TCAccelerometer {
public:
#define BMA250_I2CADDR      0x18

  enum RegisterNumber { XDataReg = 0x02, YDataReg = 0x04, ZDataReg = 0x06, TempDataReg = 0x07, RangeDataReg = 0x0f, BandwidthDataReg = 0x10, PowerModeReg = 0x11 };
  enum Bandwidth { UT64ms = 0x08, UT32ms = 0x09, UT16ms = 0x0a, UT8ms = 0x0b, UT4ms = 0x0c, UT2ms = 0x0d, UT1ms = 0x0e, UT05ms = 0x0f};
  enum RangeConst {Range2g = 0x03, Range4g = 0x05, Range8g = 0x08, Range16g = 0x0c};
  enum Powerconstants { PowerSleep = 0x80, PowerNormal = 0x00};
  TCAccelerometer();
  void init();
  void awake();
  void sleep();

  void read();
  int getTemp(); // Degree Celsius * 2
  int getX();
  int getY();
  int getZ();
private:
  int   accelX;
  int   accelY;
  int   accelZ;
  int   accelTemperature;
};

#endif
