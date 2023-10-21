#include <iostream>
#include <fstream>

#include <stdio.h>

#include "interpreter.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "You need to specify the assembled file to interpret on the commandline." << std::endl;
        return -1;
    }

    std::ifstream input_asm_file(argv[1], std::ios::binary);
    if (!input_asm_file.is_open())
    {
        std::cout << "Error while opening the file: " << strerror(errno) << std::endl;
        return -1;
    }

    Interpreter8086 interpreter;
    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input_asm_file), {});
    interpreter.interpret_bytes(buffer, std::cout);

    std::cout << std::endl;
}
