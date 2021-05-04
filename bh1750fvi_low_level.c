/*BH1750FVI C Driver*/
/*Reza Ebrahimi - https://github.com/ebrezadev*/
/*Version 1.0*/
#include "bh1750fvi.h"

/*transmits one byte of command to bh1750fvi. in case of bh1750 sensor, there's no internal register map. each 'write' to i2c is a 'command'*/
void light_i2c_write_single(uint8_t device_address, uint8_t command)
{
}

/*function to read two bytes of measured illuminance from bh1750fvi. note: there's no register address, just request two bytes of data from bh1750 (slave)*/
void light_i2c_read(uint8_t device_address, uint8_t *data_array)
{
}

/*function to initialize I2C peripheral in 100khz or 400khz*/
void bh1750_I2C_init()
{
}

/*function for delay in milliseconds*/
void delay_function(uint32_t delay_milliseconds)
{
}
