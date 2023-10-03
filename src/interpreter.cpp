#include "interpreter.h"

void Interpreter8086::interpret_bytes(char bytes[2])
{
    unsigned char high_6_bits = (bytes[1] & 0b11111100) >> 2;
    bool d_bit = bytes[1] & 0b00000010, w_bit = bytes[1] & 0b00000001;

    unsigned char mod_field = (bytes[0] & 0b11000000) >> 6;
    unsigned char reg_field = (bytes[0] & 0b00111000) >> 3;
    unsigned char rm_field = bytes[0] & 0b00000111;
}
