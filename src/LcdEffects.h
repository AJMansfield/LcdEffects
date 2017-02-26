#ifndef STRINGEFFECTS_H
#define STRINGEFFECTS_H

#ifndef CHARACTER_ROM_CODE
#define CHARACTER_ROM_CODE 0
#endif

#ifndef CACHE_CUSTOM_CHARS
#define CACHE_CUSTOM_CHARS false
#endif


#include <stdint.h>
#include <avr/pgmspace.h>
#include <string.h>
#include <Arduino.h>



class LcdEffects {
private:
	typedef struct {
		uint8_t l0 : 5;
		uint8_t l1 : 5;
		uint8_t l2 : 5;
		uint8_t l3 : 5;
		uint8_t l4 : 5;
		uint8_t l5 : 5;
		uint8_t l6 : 5;
		uint8_t l7 : 5;
	} packed_glyph_t;

	typedef void(*effect_t)(uint8_t*);

	typedef uint8_t charslot_t;



	void unpack_glyph(const packed_glyph_t& c, uint8_t* glyph);
	const packed_glyph_t get_packed_glyph(unsigned char c);
	void get_glyph(unsigned char c, uint8_t* glyph);

	void (*create_char)(unsigned char, uint8_t*);

	charslot_t char_slot = 0;
	charslot_t first_slot = 0;
	charslot_t last_slot = 8;

	inline char get_char_for_slot(charslot_t cs){
		return cs + 8;
	}

	const static unsigned char glyph_begin;
	const static unsigned char glyph_end;
	const static PROGMEM packed_glyph_t glyph_data[];



	// #if CACHE_CUSTOM_CHARS
	// typedef struct {
	// 	unsigned char c;
	// 	void (*char_effect)(uint8_t*);
	// } custom_char;
	// custom_char cache[];

	// uint8_t find_in_cache(custom_char& cc){
	// 	for(charslot_t cs = first_slot; cs < last_slot; cs++){
	// 		if(cache[cs] == cc){
	// 			return cs;
	// 		}
	// 	}

	// 	return -1;
	// }

	// unsigned char make_char(unsigned char in, )


	
	// void *bsearch(const void *__key, const void *__base, size_t __nmemb,
	// 	     size_t __size, int (*__compar)(const void *, const void *));

	// uint8_t cache_lookup(custom_char ch){

	// }

	// #endif

public:
	LcdEffects(void (*create_char)(char, uint8_t*)): create_char{create_char} {}
	~LcdEffects(){}

	void begin();
	void begin(charslot_t first_slot, charslot_t last_slot);
	void end();
	void applyEffect(char* first, char* last, effect_t char_effect);
	void applyEffect(char str[], const size_t begin, const size_t end, effect_t char_effect);

};


namespace effect {

	void invert(uint8_t* glyph);
	void underline(uint8_t* glyph);
	void drop(uint8_t* glyph);
	void nothing(uint8_t* glyph);
}


#endif