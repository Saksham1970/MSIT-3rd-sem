#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Declarations
std::ifstream InputFile;
std::ofstream OutputFile;

char whitespaces[] = {' ', '\n', '\t', '\r', '\v'};
int whitespaces_size = sizeof(whitespaces) / sizeof(*whitespaces);

int main()
{
    InputFile.open("8_whitespace.txt");
    OutputFile.open("8_shredded.txt");

    if (!InputFile)
    {
        std::cout << "Input file could not be opened! Terminating!" << std::endl;
        return 1;
    }

    if (!OutputFile)
    {
        std::cout << "Output file could not be opened! Terminating!" << std::endl;
        return 1;
    }

    char a;
    while (!InputFile.eof())
    {

        InputFile.get(a);
        bool exists = std::find(whitespaces, whitespaces + whitespaces_size, a) != whitespaces + whitespaces_size;
        if (!exists)
        {
            OutputFile << a;
        }
    }
    OutputFile.close();
    return 0;
}