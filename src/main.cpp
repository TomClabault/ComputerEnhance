#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "You need to specify the asm file to interpret on the commandline." << std::endl;
        return -1;
    }

    unsigned char buffer[2];
    std::ifstream input_asm_file(argv[1]);
    input_asm_file.read(buffer, 2);

    Interpreter8086 interpreter;
    interpreter.interpret_bytes(buffer);
}
