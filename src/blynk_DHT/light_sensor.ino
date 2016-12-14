#include <BH1750.h>

BH1750 lightMeter;

void sendSensor()
{
  uint16_t lux = lightMeter.readLightLevel();
  Blynk.virtualWrite(V7, lux);
  Serial.println(lux);


 
}

void setup()
{
  lightMeter.begin();

}
