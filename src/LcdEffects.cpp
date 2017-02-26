#include "LcdEffects.h"


#if CHARACTER_ROM_CODE == 0
#include "rom0.h"
#else
#error "Unrecognized character ROM code"
#endif


void LcdEffects::begin(){
	char_slot = first_slot;
}
void LcdEffects::begin(LcdEffects::charslot_t first, LcdEffects::charslot_t last){
	first_slot = first;
	last_slot = last;
	begin();
}
void LcdEffects::end(){

}
void LcdEffects::applyEffect(char* first, char* last, void (*char_effect)(uint8_t*)){
	for(char* it = first; it < last; it++){
		uint8_t buf[8];
		get_glyph(*it, buf);
		char_effect(buf);
		create_char(char_slot, buf);
		*it = get_char_for_slot(char_slot);

		char_slot++;
		if(char_slot >= last_slot) char_slot = first_slot;
	}
}
void LcdEffects::applyEffect(char str[], const size_t begin, const size_t end, void (*char_effect)(uint8_t*)){
	applyEffect(str + begin, str + end, char_effect);
}


void LcdEffects::unpack_glyph(const LcdEffects::packed_glyph_t& c, uint8_t* buf){
	buf[0] = c.l0;
	buf[1] = c.l1;
	buf[2] = c.l2;
	buf[3] = c.l3;
	buf[4] = c.l4;
	buf[5] = c.l5;
	buf[6] = c.l6;
	buf[7] = c.l7;
}

void LcdEffects::get_glyph(unsigned char c, uint8_t* buf){
	unpack_glyph(get_packed_glyph(c), buf);
}

const LcdEffects::packed_glyph_t LcdEffects::get_packed_glyph(unsigned char c){
	if(c < glyph_begin) c = 0;
	else if(c >= glyph_end) c = 0;
	else c -= glyph_begin;

	packed_glyph_t glyph;
	memcpy_P(&glyph, glyph_data+c, sizeof(packed_glyph_t));

	return glyph;
}

