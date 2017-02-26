

const unsigned char LcdEffects::glyph_begin = 0x20;
const unsigned char LcdEffects::glyph_end = 0x80;
const PROGMEM LcdEffects::packed_glyph_t LcdEffects::glyph_data[] =
{
{	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000	}, //  

{	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00000,
	0b00100,
	0b00000	}, // !

{	0b01010,
	0b01010,
	0b01010,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000	}, // "

{	0b01010,
	0b01010,
	0b11111,
	0b01010,
	0b11111,
	0b01010,
	0b01010,
	0b00000	}, // #

{	0b00100,
	0b01111,
	0b10100,
	0b01110,
	0b00101,
	0b11110,
	0b00100,
	0b00000	}, // $

{	0b11000,
	0b11001,
	0b00010,
	0b00100,
	0b01000,
	0b10011,
	0b00011,
	0b00000	}, // %

{	0b01100,
	0b10010,
	0b10100,
	0b01000,
	0b10101,
	0b10010,
	0b01101,
	0b00000	}, // &

{	0b01100,
	0b00100,
	0b01000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000	}, // '

{	0b00010,
	0b00100,
	0b01000,
	0b01000,
	0b01000,
	0b00100,
	0b00010,
	0b00000	}, // (

{	0b01000,
	0b00100,
	0b00010,
	0b00010,
	0b00010,
	0b00100,
	0b01000,
	0b00000	}, // )

{	0b00000,
	0b00100,
	0b10101,
	0b01110,
	0b10101,
	0b00100,
	0b00000,
	0b00000	}, // *

{	0b00000,
	0b00100,
	0b00100,
	0b11111,
	0b00100,
	0b00100,
	0b00000,
	0b00000	}, // +

{	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b01100,
	0b00100,
	0b01000,
	0b00000	}, // ,

{	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b00000,
	0b00000,
	0b00000,
	0b00000	}, // -

{	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b01100,
	0b01100,
	0b00000	}, // .

{	0b00000,
	0b00001,
	0b00010,
	0b00100,
	0b01000,
	0b10000,
	0b00000,
	0b00000	}, // /

{	0b01110,
	0b10001,
	0b10011,
	0b10101,
	0b11001,
	0b10001,
	0b01110,
	0b00000	}, // 0

{	0b00100,
	0b01100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b01110,
	0b00000	}, // 1

{	0b01110,
	0b10001,
	0b00001,
	0b00010,
	0b00100,
	0b01000,
	0b11111,
	0b00000	}, // 2

{	0b11111,
	0b00010,
	0b00100,
	0b00010,
	0b00001,
	0b10001,
	0b01110,
	0b00000	}, // 3

{	0b00010,
	0b00110,
	0b01010,
	0b10010,
	0b11111,
	0b00010,
	0b00010,
	0b00000	}, // 4

{	0b11111,
	0b10000,
	0b11110,
	0b00001,
	0b00001,
	0b10001,
	0b01110,
	0b00000	}, // 5

{	0b00110,
	0b01000,
	0b10000,
	0b11110,
	0b10001,
	0b10001,
	0b01110,
	0b00000	}, // 6

{	0b11111,
	0b00001,
	0b00010,
	0b00100,
	0b01000,
	0b01000,
	0b01000,
	0b00000	}, // 7

{	0b01110,
	0b10001,
	0b10001,
	0b01110,
	0b10001,
	0b10001,
	0b01110,
	0b00000	}, // 8

{	0b01110,
	0b10001,
	0b10001,
	0b01111,
	0b00001,
	0b00010,
	0b01100,
	0b00000	}, // 9

{	0b00000,
	0b01100,
	0b01100,
	0b00000,
	0b01100,
	0b01100,
	0b00000,
	0b00000	}, // :

{	0b00000,
	0b01100,
	0b01100,
	0b00000,
	0b01100,
	0b00100,
	0b01000,
	0b00000	}, // ;

{	0b00001,
	0b00010,
	0b00100,
	0b01000,
	0b00100,
	0b00010,
	0b00001,
	0b00000	}, // <

{	0b00000,
	0b00000,
	0b11111,
	0b00000,
	0b11111,
	0b00000,
	0b00000,
	0b00000	}, // =

{	0b10000,
	0b01000,
	0b00100,
	0b00010,
	0b00100,
	0b01000,
	0b10000,
	0b00000	}, // >

{	0b01110,
	0b10001,
	0b00001,
	0b00010,
	0b00100,
	0b00000,
	0b00100,
	0b00000	}, // ?

{	0b01110,
	0b10001,
	0b00001,
	0b01101,
	0b10101,
	0b10101,
	0b01110,
	0b00000	}, // @

{	0b01110,
	0b10001,
	0b10001,
	0b10001,
	0b11111,
	0b10001,
	0b10001,
	0b00000	}, // A

{	0b11110,
	0b10001,
	0b10001,
	0b11110,
	0b10001,
	0b10001,
	0b11110,
	0b00000	}, // B

{	0b01110,
	0b10001,
	0b10000,
	0b10000,
	0b10000,
	0b10001,
	0b01110,
	0b00000	}, // C

{	0b11100,
	0b10010,
	0b10001,
	0b10001,
	0b10001,
	0b10010,
	0b11100,
	0b00000	}, // D

{	0b11111,
	0b10000,
	0b10000,
	0b11110,
	0b10000,
	0b10000,
	0b11111,
	0b00000	}, // E

{	0b11111,
	0b10000,
	0b10000,
	0b11100,
	0b10000,
	0b10000,
	0b10000,
	0b00000	}, // F

{	0b01110,
	0b10001,
	0b10000,
	0b10111,
	0b10001,
	0b10001,
	0b01111,
	0b00000	}, // G

{	0b10001,
	0b10001,
	0b10001,
	0b11111,
	0b10001,
	0b10001,
	0b10001,
	0b00000	}, // H

{	0b01110,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b01110,
	0b00000	}, // I

{	0b00111,
	0b00010,
	0b00010,
	0b00010,
	0b00010,
	0b10010,
	0b01100,
	0b00000	}, // J

{	0b10001,
	0b10010,
	0b10100,
	0b11000,
	0b10100,
	0b10010,
	0b10001,
	0b00000	}, // K

{	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b10000,
	0b11111,
	0b00000	}, // L

{	0b10001,
	0b11011,
	0b10101,
	0b10101,
	0b10001,
	0b10001,
	0b10001,
	0b00000	}, // M

{	0b10001,
	0b10001,
	0b11001,
	0b10101,
	0b10011,
	0b10001,
	0b10001,
	0b00000	}, // N

{	0b01110,
	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b01110,
	0b00000	}, // O

{	0b11110,
	0b10001,
	0b10001,
	0b11110,
	0b10000,
	0b10000,
	0b10000,
	0b00000	}, // P

{	0b01110,
	0b10001,
	0b10001,
	0b10001,
	0b10101,
	0b10010,
	0b01101,
	0b00000	}, // Q

{	0b11110,
	0b10001,
	0b10001,
	0b11110,
	0b10100,
	0b10010,
	0b10001,
	0b00000	}, // R

{	0b01111,
	0b10000,
	0b10000,
	0b01110,
	0b00001,
	0b00001,
	0b11110,
	0b00000	}, // S

{	0b11111,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00000	}, // T

{	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b01110,
	0b00000	}, // U

{	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b10001,
	0b01010,
	0b00100,
	0b00000	}, // V

{	0b10001,
	0b10001,
	0b10001,
	0b10101,
	0b10101,
	0b10101,
	0b01010,
	0b00000	}, // W

{	0b10001,
	0b10001,
	0b01010,
	0b00100,
	0b01010,
	0b10001,
	0b10001,
	0b00000	}, // X

{	0b10001,
	0b10001,
	0b01010,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00000	}, // Y

{	0b11111,
	0b00001,
	0b00010,
	0b00100,
	0b01000,
	0b10000,
	0b11111,
	0b00000	}, // Z

{	0b01110,
	0b01000,
	0b01000,
	0b01000,
	0b01000,
	0b01000,
	0b01110,
	0b00000	}, // [

{	0b10001,
	0b01010,
	0b11111,
	0b00100,
	0b11111,
	0b00100,
	0b00100,
	0b00000	}, // ¥

{	0b01110,
	0b00010,
	0b00010,
	0b00010,
	0b00010,
	0b00010,
	0b01110,
	0b00000	}, // ]

{	0b00100,
	0b01010,
	0b10001,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000	}, // ^

{	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b11111,
	0b00000	}, // _

{	0b01000,
	0b00100,
	0b00010,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000	}, // `

{	0b00000,
	0b00000,
	0b01110,
	0b00001,
	0b01111,
	0b10001,
	0b01111,
	0b00000	}, // a

{	0b10000,
	0b10000,
	0b10110,
	0b11001,
	0b10001,
	0b10001,
	0b11110,
	0b00000	}, // b

{	0b00000,
	0b00000,
	0b01110,
	0b10000,
	0b10000,
	0b10001,
	0b01110,
	0b00000	}, // c

{	0b00001,
	0b00001,
	0b01101,
	0b10011,
	0b10001,
	0b10001,
	0b01111,
	0b00000	}, // d

{	0b00000,
	0b00000,
	0b01110,
	0b10001,
	0b11111,
	0b10000,
	0b01110,
	0b00000	}, // e

{	0b00110,
	0b01001,
	0b01000,
	0b11100,
	0b01000,
	0b01000,
	0b01000,
	0b00000	}, // f

{	0b00000,
	0b01111,
	0b10001,
	0b10001,
	0b01111,
	0b00001,
	0b01110,
	0b00000	}, // g

{	0b10000,
	0b10000,
	0b10110,
	0b11001,
	0b10001,
	0b10001,
	0b10001,
	0b00000	}, // h

{	0b00100,
	0b00000,
	0b01100,
	0b00100,
	0b00100,
	0b00100,
	0b01110,
	0b00000	}, // i

{	0b00010,
	0b00000,
	0b00110,
	0b00010,
	0b00010,
	0b10010,
	0b01100,
	0b00000	}, // j

{	0b10000,
	0b10000,
	0b10010,
	0b10100,
	0b11000,
	0b10100,
	0b10010,
	0b00000	}, // k

{	0b01100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b01110,
	0b00000	}, // l

{	0b00000,
	0b00000,
	0b11010,
	0b10101,
	0b10101,
	0b10001,
	0b10001,
	0b00000	}, // m

{	0b00000,
	0b00000,
	0b10110,
	0b11001,
	0b10001,
	0b10001,
	0b10001,
	0b00000	}, // n

{	0b00000,
	0b00000,
	0b01110,
	0b10001,
	0b10001,
	0b10001,
	0b01110,
	0b00000	}, // o

{	0b00000,
	0b00000,
	0b11110,
	0b10001,
	0b11110,
	0b10000,
	0b10000,
	0b00000	}, // p

{	0b00000,
	0b00000,
	0b01101,
	0b10011,
	0b01111,
	0b00001,
	0b00001,
	0b00000	}, // q

{	0b00000,
	0b00000,
	0b10110,
	0b11001,
	0b10000,
	0b10000,
	0b10000,
	0b00000	}, // r

{	0b00000,
	0b00000,
	0b01110,
	0b10000,
	0b01110,
	0b00001,
	0b11110,
	0b00000	}, // s

{	0b01000,
	0b01000,
	0b11100,
	0b01000,
	0b01000,
	0b01001,
	0b00110,
	0b00000	}, // t

{	0b00000,
	0b00000,
	0b10001,
	0b10001,
	0b10001,
	0b10011,
	0b01101,
	0b00000	}, // u

{	0b00000,
	0b00000,
	0b10001,
	0b10001,
	0b10001,
	0b01010,
	0b00100,
	0b00000	}, // v

{	0b00000,
	0b00000,
	0b10001,
	0b10001,
	0b10101,
	0b10101,
	0b01010,
	0b00000	}, // w

{	0b00000,
	0b00000,
	0b10001,
	0b01010,
	0b00100,
	0b01010,
	0b10001,
	0b00000	}, // x

{	0b00000,
	0b00000,
	0b10001,
	0b10001,
	0b01111,
	0b00001,
	0b01110,
	0b00000	}, // y

{	0b00000,
	0b00000,
	0b11111,
	0b00010,
	0b00100,
	0b01000,
	0b11111,
	0b00000	}, // z

{	0b00010,
	0b00100,
	0b00100,
	0b01000,
	0b00100,
	0b00100,
	0b00010,
	0b00000	}, // {

{	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00000	}, // |

{	0b01000,
	0b00100,
	0b00100,
	0b00010,
	0b00100,
	0b00100,
	0b01000,
	0b00000	}, // }

{	0b00000,
	0b00100,
	0b00010,
	0b11111,
	0b00010,
	0b00100,
	0b00000,
	0b00000	}, // →

{	0b00000,
	0b00100,
	0b01000,
	0b11111,
	0b01000,
	0b00100,
	0b00000,
	0b00000	} // ←
};