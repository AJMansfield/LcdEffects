/**
 *	@file	LcdEffects.h
 *	@brief	Arduino library for doing character effects on LCDs
 *	@author	Anson Mansfield
 *	@date 	2017-02-26
 */

#ifndef STRINGEFFECTS_H
#define STRINGEFFECTS_H

#ifndef CACHE_CUSTOM_CHARS
#define CACHE_CUSTOM_CHARS true
#endif

#if CACHE_CUSTOM_CHARS
#include "Cache.h"
#endif


#include <stdint.h>
#include <avr/pgmspace.h>
#include <string.h>


/**
 *	@brief	Class wrapper for LCD effects library.
 *	@param	rom	Different LCDs have different character ROMS on them; in order to allow you
 *				select the number corresponding to the character rom you have to ensure the
 *				effect characters are consistent with normal text.
 *	
 *	This library allows you to do text effects on an LCD screen.
 *	You can have multiple instances of this library at one time, to allow more flexibility
 *	in putting different text on multiple different LCDs.
 *
 *	Note that only up to 8 different characters can have effects applied at one time.
 *	Normally this only counts unique character/format combinations. For example, the string
 *	"xxxxxxxx", if formatted all with underlining, would only take one slot. If you formatted
 *	the first half with underlining, and the second in italics, it would take two slots.
 *
 *	Note that if caching is disabled, this limit is reduced to 8 characters _total_, regardless
 *	of duplicate characters or formatting.
 */
template<int rom = 0>
class LcdEffects {
public:

	typedef void(*effect_t)(uint8_t*);
	typedef uint8_t charslot_t;

	/**
	 *	@brief	Creates an LcdEffects objectClass wrapper for LCD effects library.
	 *	@param	create_char	A function pointer to the method for creating a custom lcd
	 *						character on screen.
	 */
	LcdEffects(void (*create_char)(char, uint8_t*)): create_char{create_char} {}

	/**
	 *	@brief	When caching is disabled, gall before applying effects to reduce flickering.
	 *
	 *	This function normally does nothing, but when character caching is disabled this can
	 *	help reduce the flickering caused by rewriting the LCD's character RAM.
	 *	Call every time before you start applying effects to a string.
	 */
	void begin();

	/**
	 *	@brief	Restricts the library to only use character slots within a certian range.
	 *	@param	first_slot	The first slot the library should use.
	 *	@param	last_slot	The last slot of the range, or the first disallowed.
	 *
	 *	If you are using your own custom characters on the LCD, use this method to 
	 *	restrict this library from overwriting your custom characters.
	 */
	void setSlotRange(charslot_t first_slot, charslot_t last_slot);

	/**
	 *	@brief	Applies an effect to the character.
	 *	@param	c	The character to apply the affect to.
	 *	@param	effect	The effect to apply.
	 *
	 *	This method creates a custom character for the passed character, and replaces the
	 *	character with the corresponding character code.
	 */
	void applyEffect(char& c, effect_t effect);

	/**
	 *	@brief	Applies an effect to the string pointer range.
	 *	@param	first	The beginning element of the range.
	 *	@param	last	The ending element of the range.
	 *
	 *	This method creates custom characters for each character in the range, and replaces
	 *	those characters with the corresponding character code.
	 */
	void applyEffect(char* first, char* last, effect_t effect);

	/**
	 *	@brief	Applies an effect to characters in a range.
	 *	@param	begin	The beginning element of the range.
	 *	@param	end	The ending element of the range.
	 *
	 *	This method creates custom characters for characters in the range [begin, end), and
	 *	replaces those characters with the corresponding character code.
	 */
	void applyEffect(char str[], const size_t begin, const size_t end, effect_t effect);

private:
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
	#if !CACHE_CUSTOM_CHARS
	char_slot = first_slot;
	#endif
}

template<int rom>
void LcdEffects<rom>::setSlotRange(LcdEffects::charslot_t first, LcdEffects::charslot_t last){
	first_slot = first;
	last_slot = last;
	#if CACHE_CUSTOM_CHARS
	cache.setRange(first_slot,last_slot);
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