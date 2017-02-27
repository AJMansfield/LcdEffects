#ifndef STRINGEFFECTS_H
#define STRINGEFFECTS_H

#ifndef CACHE_CUSTOM_CHARS
#define CACHE_CUSTOM_CHARS false
#endif

#if CACHE_CUSTOM_CHARS
#include "Cache.h"
#endif


#include <stdint.h>
#include <avr/pgmspace.h>
#include <string.h>
#define INCLUDE_PRINTF
#include <Arduino.h>



template<int rom = 0>
class LcdEffects {
public:
	typedef void(*effect_t)(uint8_t*);
	typedef uint8_t charslot_t;

	LcdEffects(void (*create_char)(char, uint8_t*)): create_char{create_char} {}

	void begin();
	void begin(charslot_t first_slot, charslot_t last_slot);
	void end();
	void applyEffect(char& c, effect_t effect);
	void applyEffect(char* first, char* last, effect_t effect);
	void applyEffect(char str[], const size_t begin, const size_t end, effect_t effect);

//private:
	struct packed_glyph_t{
		uint8_t l0 : 5;
		uint8_t l1 : 5;
		uint8_t l2 : 5;
		uint8_t l3 : 5;
		uint8_t l4 : 5;
		uint8_t l5 : 5;
		uint8_t l6 : 5;
		uint8_t l7 : 5;
	};

	void unpack_glyph(const packed_glyph_t& c, uint8_t* glyph);
	const packed_glyph_t get_packed_glyph(unsigned char c);
	void get_glyph(unsigned char c, uint8_t* glyph);
	unsigned char make_char(unsigned char c, effect_t effect);

	void (*create_char)(unsigned char, uint8_t*);

	
	charslot_t first_slot = 0;
	charslot_t last_slot = 8;

	inline char get_char_for_slot(charslot_t cs){
		return cs + 8;
	}

	const static unsigned char glyph_begin;
	const static unsigned char glyph_end;
	const static PROGMEM packed_glyph_t glyph_data[];


	#if CACHE_CUSTOM_CHARS

	struct cache_t {
		effect_t effect;
		unsigned char c;
		constexpr bool operator==(const cache_t& rhs) const{
			return effect == rhs.effect && c == rhs.c;
		}
	};

	Cache<cache_t, charslot_t, 8> cache;

	#else
	charslot_t char_slot = 0;
	#endif


};

template<int rom>
void LcdEffects<rom>::begin(){
	#if CACHE_CUSTOM_CHARS
	cache.setRange(first_slot,last_slot);
	#else
	char_slot = first_slot;
	#endif
}
template<int rom>
void LcdEffects<rom>::begin(LcdEffects::charslot_t first, LcdEffects::charslot_t last){
	first_slot = first;
	last_slot = last;
	begin();
}
template<int rom>
void LcdEffects<rom>::end(){
	#if CACHE_CUSTOM_CHARS
	cache_t empty = {nullptr,0};
	cache.clear(empty);
	#endif
}
template<int rom>
void LcdEffects<rom>::applyEffect(char* first, char* last, effect_t effect){
	for(char* it = first; it < last; it++){

		applyEffect(*it, effect);

		#if !CACHE_CUSTOM_CHARS
		char_slot++;
		if(char_slot >= last_slot) char_slot = first_slot;
		#endif
	}
}
template<int rom>
void LcdEffects<rom>::applyEffect(char str[], const size_t begin, const size_t end, effect_t effect){
	applyEffect(str + begin, str + end, effect);
}

template<int rom>
void LcdEffects<rom>::applyEffect(char& c, effect_t effect){
	#if CACHE_CUSTOM_CHARS
	cache_t key = {effect, c};
	auto cache_result = cache.get(key);
	if(cache_result.old){
		c = get_char_for_slot(cache_result.index);
		return;
	}
	#endif

	uint8_t buf[8];
	get_glyph(c, buf);
	effect(buf);

	#if CACHE_CUSTOM_CHARS
	create_char(cache_result.index, buf);
	c = get_char_for_slot(cache_result.index);
	#else
	create_char(char_slot, buf);
	c = get_char_for_slot(char_slot);
	#endif
}

template<int rom>
void LcdEffects<rom>::unpack_glyph(const LcdEffects::packed_glyph_t& c, uint8_t* buf){
	buf[0] = c.l0;
	buf[1] = c.l1;
	buf[2] = c.l2;
	buf[3] = c.l3;
	buf[4] = c.l4;
	buf[5] = c.l5;
	buf[6] = c.l6;
	buf[7] = c.l7;
}

template<int rom>
void LcdEffects<rom>::get_glyph(unsigned char c, uint8_t* buf){
	unpack_glyph(get_packed_glyph(c), buf);
}

template<int rom>
const typename LcdEffects<rom>::packed_glyph_t LcdEffects<rom>::get_packed_glyph(unsigned char c){
	if(c < glyph_begin) c = 0;
	else if(c >= glyph_end) c = 0;
	else c -= glyph_begin;

	packed_glyph_t glyph;
	memcpy_P(&glyph, glyph_data+c, sizeof(packed_glyph_t));

	return glyph;
}

#endif