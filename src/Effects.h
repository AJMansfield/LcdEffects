/**
 *	@file	Effects.h
 *	@brief	A few common text effects.
 *	@author	Anson Mansfield
 *	@date 	2017-02-26
 */

#ifndef EFFECTS_H
#define EFFECTS_H

#include <stdint.h>

/**
 *	@brief	A collection of pre-defined text effects.
 *	
 *	Several commonly-used effects are included here for utility and to serve
 *	as examples for how to implement your own effects.
 */
namespace effect {

	typedef void(*effect_t)(uint8_t*);

	void invert(uint8_t* glyph);
	void underline(uint8_t* glyph);
	void drop(uint8_t* glyph);
	void thin(uint8_t* glyph);
	void narrow(uint8_t* glyph);
	void italic(uint8_t* glyph);
	void bold(uint8_t* glyph);
	void normal(uint8_t* glyph);
}

#endif