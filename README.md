# BH1750FVI Light Intensity Sensor C Driver
* version 1.0
* Reza Ebrahimi

This library is written in **portable C**, and is **MCU independent**. BH1750FVI is a digital Ambient Light Sensor IC for I2C bus interface. This module is most suitable to obtain the ambient light data for adjusting LCD and Keypad backlight power of Mobile phones. It is possible to detect wide range at High resolution ( 1 - 65535 lx ) (ROHM Semiconductor datasheet). In order to implement it to your MCU of choice, you need to manipulate functions inside bh1750fvi_low_level.c file (I2C configurations and delay function) and leave other files as they are.

BH1750FVI C library abstracts away the internals of the hardware, using high level functions (description below). There's also an **automatic mode** included in this driver.

This library is written based on the 'Ambient Light Sensor IC Series - Digital 16bit Serial Output Type Ambient Light Sensor IC - BH1750FVI (by ROHM Semiconductor)' and is not influenced by other libraries out there. Any resemblance to pre-existing code is unintentional.

## GENERAL INFORMATION

Please note, there's no register map inside BH1750FVI sensor; Any "write" to BH1750FVI I2C address is considered a command, and all "reads" are two bytes of ambient light metering in Lux with a coefficient of 1.2 (decimal).

In order to achieve an absolute measure of ambient light in Lux, you need to divide the result by 1.2; which is avoided in this driver because of implementation of division in embedded systems (especially float numbers).

BH1750FVI sensor has two selectable I2C addresses, which are chosen according to the ADDRESS pin. These two are 0X23 and 0X5C (ADDRESS1 and ADDRESS2 in driver).

BH1750FVI sensor can meter light in continuous or one-time modes. The differences are in power consumption and speed; Continuous consumes more power but there's no need to send a 'update metering data command' each time. In one-time mode after updating the metering data, sensor goes into power saving mode ready for commands.

There are three possible selectable metering resolutions with different measuring times: Low, High 1 and High 2. Low mode has a resolution of 4 Lux and lowest measuring time of 16 ms (can be changed, more on that later). H1 mode has a resolution of 1 Lux and measuring time of 120 ms, H2 has a resolution of 0.5 Lux and measuring time of 120 ms (generally).

The influence of a optical window could be also compensated, using "change Measuring Time feature". For instance, an optical window with -1 EV reduction in light can be compensated by doubling the measuring time.

As mentioned, the selection of resolution and measuring time is manual, but an added feature in this driver is the **automatic** selection of resolution that switches between three metering resolutions.

## HOW TO USE

As mentioned earlier, first you need to implement low level settings inside bh1750fvi_low_level.c which consists of I2C settings and a delay function. In order to use, the first function to call is lightSensor_begin(uint8_t address, uint8_t mode_of_operation). address is ADDRESS1 or ADDRESS2, mode_of_operation is CONTINUOUS_H_1_MODE, CONTINUOUS_H_2_MODE, CONTINUOUS_L_MODE, ONE_TIME_H_1_MODE, ONE_TIME_H_2_MODE and ONE_TIME_L_MODE in manual modes and CONTINUOUS_AUTOMATIC or ONE_TIME_AUTOMATIC in automatic modes. Finally, metered 16-bits results could be read with lightSensor_meter().

## C FUNCTIONS

Functions can be categorized in different levels. Higher level functions use Lower level functions.

LEVEL 1:
* void light_i2c_write_single(uint8_t device_address, uint8_t command)
* void light_i2c_read(uint8_t device_address, uint8_t *data_array)
* void bh1750_I2C_init()
* void delay_function(uint32_t delay_milliseconds)

LEVEL 2:
* void lightSensor_mode(uint8_t command)
* static void lightSensor_readBuffer()

LEVEL 3:
* void lightSensor_begin(uint8_t address, uint8_t mode_of_operation)
* static void lightSensor_automaticResolutionSet(uint16_t meter_value)
* uint16_t lightSensor_meter()

## TO BE ADDED

The optical window compensation feature is not present in version 1.0.
