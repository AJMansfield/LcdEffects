#include "Effects.h"

#include <avr/pgmspace.h>
#include <string.h>

void effect::invert(uint8_t* dat){
	*(dat) = ~*(dat);
	*(dat+1) = ~*(dat+1);
	*(dat+2) = ~*(dat+2);
	*(dat+3) = ~*(dat+3);
	*(dat+4) = ~*(dat+4);
	*(dat+5) = ~*(dat+5);
	*(dat+6) = ~*(dat+6);
	*(dat+7) = ~*(dat+7);
}
void effect::underline(uint8_t* dat){
	*(dat+7) = 0xFF;
}
void effect::drop(uint8_t* dat){
	memmove(dat+1, dat, 7);
	*dat = 0x00;
}
void effect::thin(uint8_t* dat){
	for(uint8_t i = 0; i < 8; i++){
		*(dat+i) = ((*(dat+i) >> 1)&0xFE) | (*(dat+i)&0x01); //discard 2nd column
	}
}
void effect::narrow(uint8_t* dat){
	for(uint8_t i = 0; i < 8; i++){
		*(dat+i) = ((*(dat+i) >> 1)&0xFE) | (*(dat+i)&0x03); //merge 2nd and 3rd column together
	}
}
void effect::italic(uint8_t* dat){
	narrow(dat);

	for(uint8_t i = 4; i < 8; i++){
		*(dat+i) = *(dat+i) << 1;
	}
}
void effect::bold(uint8_t* dat){
	narrow(dat);
	for(uint8_t i = 0; i < 8; i++){
		*(dat+i) |= *(dat+i) << 1;
	}
}
void effect::normal(uint8_t* dat){
}