#include <iostream>

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "You need to specify the asm file to interpret on the commandline." << std::endl;
        return -1;
    }

    FILE* input_asm_file = fopen(argv[1]);
}
