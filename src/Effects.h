#ifndef EFFECTS_H
#define EFFECTS_H

#include <stdint.h>

namespace effect {

	void invert(uint8_t* glyph);
	void underline(uint8_t* glyph);
	void drop(uint8_t* glyph);
	void nothing(uint8_t* glyph);
}

#endif