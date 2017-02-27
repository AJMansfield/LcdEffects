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
void effect::nothing(uint8_t* dat){
}