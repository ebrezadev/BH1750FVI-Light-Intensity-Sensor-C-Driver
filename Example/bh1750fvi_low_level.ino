#include "bh1750fvi.h"
#include <Wire.h>

#define I2C_SPEED       400000        /*according to datasheet, bh1750fvi supports 400khz i2c speed*/

/*transmits one byte of command to bh1750fvi*/
void light_i2c_write_single(uint8_t device_address, uint8_t command)
{
  Wire.beginTransmission(device_address);
  Wire.write(command);
  Wire.endTransmission(device_address);
}

/*function to read two bytes of measured illuminance from bh1750fvi*/
void light_i2c_read(uint8_t device_address, uint8_t *data_array)
{
  Wire.requestFrom(device_address, 2, 0);
  while (Wire.available())
  {
    *data_array = Wire.read();
    data_array++;
  }
}

/*function to initialize I2C peripheral in 100khz or 400khz*/
void bh1750_I2C_init()
{
  Wire.begin();
  Wire.setClock(I2C_SPEED);
}

/*function for delay in milliseconds*/
void delay_function(uint32_t delay_milliseconds)
{
  delay(delay_milliseconds);
}
