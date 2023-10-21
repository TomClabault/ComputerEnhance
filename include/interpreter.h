#ifndef INTERPRETER_8086_H
#define INTERPRETER_8086_H

#include <iostream>
#include <vector>

class Interpreter8086
{
public:
    static const std::vector<std::string> INSTRUCTION_MNEMONIC_TABLE;
    static const char REGISTER_NAME_TABLE[][2][3];

    void interpret_bytes(std::vector<unsigned char>& two_bytes, std::ostream& decode_stream);
    std::string get_register_name(unsigned char reg_field, unsigned char w_bit);
};

#endif
