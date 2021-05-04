# BH1750FVI Light Intensity Sensor C Driver
* version 1.0
* Reza Ebrahimi

This library is written in **portable C**, and is **MCU independent**. BH1750FVI is an digital Ambient Light Sensor IC for I2C bus interface. This IC is most suitable to obtain the ambient light data for adjusting LCD and Keypad backlight power of Mobile phones. It is possible to detect wide range at High resolution ( 1 - 65535 lx ) (ROHM Semiconductor datasheet). In order to implement it to your MCU of choice, you need to manipulate functions inside bh1750fvi_low_level.c file (I2C configurations and delay function) and leave other files as they are.

BH1750FVI C library abstracts away the internals of the hardware, using high level functions (description below). There's also an **automatic mode** included in this driver.

This library is written based on the 'Ambient Light Sensor IC Series - Digital 16bit Serial Output Type Ambient Light Sensor IC - BH1750FVI (by ROHM Semiconductor)' and is not influenced by other libraries out there. Any resemblance to pre-existing code is unintentional.

## HOW TO USE

As mentioned earlier, first you need to implement low level settings inside bh1750fvi_low_level.c which consists of I2C settings and a delay function. Please note, there's no register map inside BH1750FVI sensor; Any "write" to BH1750FVI I2C address is considered a command, and all "reads" are two bytes of ambient light metering in Lux with a coefficient of 1.2 (decimal). In order to 

  
