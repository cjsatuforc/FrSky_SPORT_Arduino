/*
  FrSky S.Port to UART Remote (Type B) converter class for Teensy 3.x and 328P
  based boards (e.g. Pro Mini, Nano, Uno)
  (c) Pawelsky 20150725
  Not for commercial use

  Note that only analog ports ADC3 and ADC4 are implemented, not the UART part.
*/

#ifndef _FRSKY_SPORT_SENSOR_SP2UART_H_
#define _FRSKY_SPORT_SENSOR_SP2UART_H_

#include "FrSkySportSensor.h"

#define SP2UARTB_DEFAULT_ID ID7
#define SP2UARTB_DATA_COUNT 2
#define SP2UARTB_ADC3_DATA_ID 0x0900
#define SP2UARTB_ADC4_DATA_ID 0x0910

#define SP2UARTB_ADC3_DATA_PERIOD 500
#define SP2UARTB_ADC4_DATA_PERIOD 500

class FrSkySportSensorSp2uart : public FrSkySportSensor {
public:
  FrSkySportSensorSp2uart(SensorId id = SP2UARTB_DEFAULT_ID);
  void setData(float adc3, float adc4);
  virtual void send(FrSkySportSingleWireSerial &serial, uint8_t id,
                    uint32_t now);

private:
  uint32_t adc3;
  uint32_t adc4;
  uint32_t adc3Time;
  uint32_t adc4Time;
};

#endif // _FRSKY_SPORT_SENSOR_SP2UART_H_
