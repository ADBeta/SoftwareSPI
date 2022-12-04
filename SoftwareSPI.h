/* Software defined SPI protocol, including multi-slave support, configurable
 * clock speed, delay before transmission, clock polarity and clock phase
 * (CPOL + CPHA).
 *	
 * Uses chASM for hardware control. See https://github.com/ADBeta/chASM for
 * more information. 
 *
 * Software Configuration Options
 *	CPOL - Defines polarity of the clock, eg rising edve vs falling edge.
 *		0 = IDLE at LOW, ACTIVE rising edge.
 *		1 = IDLE at HIGH, ACTIVE at falling edge.
 *	
 *	CPHA - Defines the phase of data, TODO complicated
 *
 
 
 
  TODO See if syncronous read and write is popular enough to impliment
  research what defines SPI vs a generic serial interface
  
 
 * ADBeta 04 Dec 2022
*/

#include "Arduino.h"
#include "chASM.h"

#ifndef SOFTWARESPI_H
#define SOFTWARESPI_H

class SoftwareSPI {
	public:
	//Constructor. SCLK MISO MOSI SS
	SoftwareSPI(uint8_t SCLK, uint8_t MISO, uint8_t MOSI, uint8_t SS); 
	
	//Sets CPOL to 1 or 0. Defaults to 0 (rising edge trigger, idle low)
	
	//Sets CPHA 
	
	
	
	//private
	/** Hardware pins in chASM object pointer **********************************
		SCLK | Master -> Slave   Output
		MOSI | Master -> Slave   Output
		MISO | Slave -> Master   Input
		SS   | Master -> Slave   Output
	**/
	chASM *p_SCLK;
	chASM *p_MISO;
	chASM *p_MOSI;
	chASM *p_SS;
	
	//CPOL and CPHA flags. Used when hardware functions are called.
	bool CPOL = 0;
	bool CPHA = 0;
	
	
}; //class SoftwareSPI

#endif
