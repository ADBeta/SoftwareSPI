/*

	SD Card boots into SD mode. To change to SPI mode, assert CS, then issue a reset command
*/

#include "SoftwareSPI.h"

#define SCLK 13 //Serial Clock
#define MISO 7 //Receive from slave
#define MOSI 11 //Send to slave
#define SS 10 //Slave Select for each device

SoftwareSPI test(SCLK,MISO,MOSI,SS);

void setup() {
	Serial.begin(9600);
}

void loop() {
}
