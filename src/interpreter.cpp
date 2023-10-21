#include "interpreter.h"

std::vector<std::string> initialize_mnemonic_table()
{
    std::vector<std::string> table(64);

    table[0b100010] = "mov";

    return table;
}

const std::vector<std::string> Interpreter8086::INSTRUCTION_MNEMONIC_TABLE = initialize_mnemonic_table();
const char Interpreter8086::REGISTER_NAME_TABLE[][2][3] =
{
    {"al", "ax"},
    {"cl", "cx"},
    {"dl", "dx"},
    {"bl", "bx"},
    {"ah", "sp"},
    {"ch", "bp"},
    {"dh", "si"},
    {"bh", "di"}
};

void Interpreter8086::interpret_bytes(std::vector<unsigned char>& bytes, std::ostream &decode_stream)
{
    for (int i = 0; i < bytes.size() / 2; i++)
    {
        int first_byte_index = i * 2 + 0;
        int second_byte_index = i * 2 + 1;

        //Instruction itself
        unsigned char high_6_bits = (bytes[first_byte_index] & 0b11111100) >> 2;
        //D and W bits
        //If D bit is 0, the register field is the source
        //If D bit is 1, the register field is the destination
        unsigned char d_bit = bytes[first_byte_index] & 0b00000010;
        //If the W bit is 1, it's wide and we're moving 16 bits
        //otherwise, it's not wide and we're moving 8 bits
        unsigned char w_bit = bytes[first_byte_index] & 0b00000001;

        //For the MOV instruction, the mod field encodes whether this is a
        //memory to register or register to memory move
        unsigned char mod_field = (bytes[second_byte_index] & 0b11000000) >> 6;
        //For the MOV instruction, the reg field encodes the register
        unsigned char reg_field = (bytes[second_byte_index] & 0b00111000) >> 3;
        //The rm field either encodes a location in memory or a register
        //depending on the value of the mod field
        //If the RM field encodes a register this means that we have two registers at our disposal:
        //The reg field and the rm field
        //The one that is the destination depends on the D bit
        //If D bit is 0, the register field is the source
        //If D bit is 1, the register field is the destination
        unsigned char rm_field = bytes[second_byte_index] & 0b00000111;

        decode_stream << Interpreter8086::INSTRUCTION_MNEMONIC_TABLE[high_6_bits] << " ";

        const char* destination_register = Interpreter8086::REGISTER_NAME_TABLE[d_bit ? reg_field : rm_field][w_bit];
        const char* source_register = Interpreter8086::REGISTER_NAME_TABLE[d_bit ? rm_field : reg_field][w_bit];

        decode_stream << destination_register << ", ";
        decode_stream << source_register << std::endl;
    }
}
