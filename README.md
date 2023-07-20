# Temperature/Humidity Station
## Description:
Temperature and humidity station that displays the current temperature and humidity.  
on a LCD display.
-- May add an esp8266 web server to upload the values there
## Components:
* Nucleo F446RE board
* DHT22 Temperature/Humidity sensor
* Potentiometer
* 16x2 LCD
* Jumper wires
* Text editor/IDE - STM32 CubeIDE

## Circuit Wiring
![Fritzing_img](media/DHT22_LCD_Project.png?raw=true)
![Circuit](media/circuit.jpg?raw=true)

## Nucleo Configurations
 **Select the correct board(F446RE)**
![board_select](media/board_select.png?raw=true)<br>

**Set the GPIO pins**
![pins](media/pins.JPG?raw=true)<br>

**Set the Clock Configuration**
![Clock_config](media/clk.JPG?raw=true)
**Set the timer setting**<br>

![tim6](media/tim6.JPG?raw=true)
* Once these configuration are set just save and wait for the header/source files to be created
<br>

**Make sure to include the LCD header/source files**
![main](media/main.JPG?raw=true)

## Coded needed in main.c
**First Part**
![First part](media/First_part.png?raw=true)<br>

**Second Part**
![Second part](media/Second_part.png?raw=true)<br>

**Third Part**
![Third part](media/Third_part.png?raw=true)<br>

