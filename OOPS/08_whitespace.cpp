#include <iostream> // Header files
#include <fstream>
#include <string>
#include <algorithm>

// Declarations
std::ifstream InputFile;
std::ofstream OutputFile;

// WhiteSpace character set
char whitespaces[] = {' ', '\n', '\t', '\r', '\v'};
int whitespaces_size = sizeof(whitespaces) / sizeof(*whitespaces);

// Driver code
int main()
{
    // Open the input and output files
    InputFile.open("08_whitespace.txt");
    OutputFile.open("08_shredded.txt");

    // Cant open the input file
    if (!InputFile)
    {
        std::cout << "Input file could not be opened! Terminating!" << std::endl;
        return 1;
    }

    // Cant open the output file
    if (!OutputFile)
    {
        std::cout << "Output file could not be opened! Terminating!" << std::endl;
        return 1;
    }

    // a is the iterated character in inputfile
    char a;
    while (!InputFile.eof()) // Not end of file
    {
        InputFile.get(a);

        // Check if a in whitespace character set
        bool exists = std::find(whitespaces, whitespaces + whitespaces_size, a) != whitespaces + whitespaces_size;

        // If a not whitespace write in output file
        if (!exists)
            OutputFile << a;
    }

    // Close the output file
    OutputFile.close();

    return 0;
}