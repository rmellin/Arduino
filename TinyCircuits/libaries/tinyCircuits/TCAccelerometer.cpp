#include "Arduino.h"
#include "Wire.h"
#include "TCAccelerometer.h"


TCAccelerometer::TCAccelerometer() {
}

void TCAccelerometer::init() {
    Wire.begin();
    // Setup the range measurement setting
    Wire.beginTransmission(BMA250_I2CADDR);
    Wire.write(RangeDataReg);
    Wire.write(Range2g);
    Wire.endTransmission();
  
    // Setup the bandwidth
    Wire.beginTransmission(BMA250_I2CADDR);
    Wire.write(BandwidthDataReg);
    Wire.write(UT64ms);
    Wire.endTransmission();

    // Setup the power setting
    Wire.beginTransmission(BMA250_I2CADDR);
    Wire.write(PowerModeReg);
    Wire.write(PowerNormal);
    Wire.endTransmission();
}

void TCAccelerometer::awake() {
    // Setup the power setting
    Wire.beginTransmission(BMA250_I2CADDR);
    Wire.write(PowerModeReg);
    Wire.write(PowerNormal);
    Wire.endTransmission();
}

void TCAccelerometer::sleep() {
    // Setup the power setting
    Wire.beginTransmission(BMA250_I2CADDR);
    Wire.write(PowerModeReg);
    Wire.write(PowerSleep);
    Wire.endTransmission();
}

void TCAccelerometer::read() {
    uint8_t readBuff[8];
  
    // Read the 7 data bytes from the BMA250
    Wire.beginTransmission(BMA250_I2CADDR);
    Wire.write(XDataReg); // starting with register address 2
    Wire.endTransmission();
    Wire.requestFrom(BMA250_I2CADDR,7);
  
    for(int i = 0; i < 7;i++) {
      readBuff[i] = Wire.read();
    }
  
    accelX = readBuff[1] << 8;
    accelX |= readBuff[0];
    accelX >>= 6;
  
    accelY = readBuff[3] << 8;
    accelY |= readBuff[2];
    accelY >>= 6;
  
    accelZ = readBuff[5] << 8;
    accelZ |= readBuff[4];
    accelZ >>= 6;  

    accelTemperature = readBuff[6] + 48; // Degree Celsius * 2
  }

int TCAccelerometer::getTemp() { return accelTemperature; }
int TCAccelerometer::getX() { return accelX; }
int TCAccelerometer::getY() { return accelY; }
int TCAccelerometer::getZ() { return accelX; }
