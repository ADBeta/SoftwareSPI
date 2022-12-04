#include "Arduino.h"
#include "chASM.h"
#include "SoftwareSPI.h"

SoftwareSPI::SoftwareSPI(uint8_t SCLK, uint8_t MISO, uint8_t MOSI, uint8_t SS) {
	//Create a chASM object for each pin, then set the pointer (p_) to the
	//address of the real (r_) object
	static chASM r_SCLK(SCLK);
	p_SCLK = &r_SCLK;
	//
	static chASM r_MISO(MISO);
	p_MISO = &r_MISO;
	//
	static chASM r_MOSI(MOSI);
	p_MOSI = &r_MOSI;
	//
	static chASM r_SS(SS);
	p_SS = &r_SS;
	
	//SS is ALWAYS active LOW, so set HIGH
	p_SS.write(HIGH);
}
	
