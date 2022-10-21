#include <iostream> // Header Files

// Function Overloading of average function
int average(int a, int b) { return (a + b) / 2; }
int average(int a, int b, int c) { return (a + b + c) / 3; }
float average(float a, float b) { return (a + b) / 2; }

// Driver code
int main()
{

    // Variable declaration
    int a = 10, b = 20, c = 30;
    float af = 8.6, bf = 3.5;

    // Calling the function in different ways
    std::cout << "Average of 2 integers 10 and 20 is: " << average(a, b) << std::endl;
    std::cout << "Average of 3 integers 10 20 and 30 is: " << average(a, b, c) << std::endl;
    std::cout << "Average of 2 flaots 8.6 and 3.5 is: " << average(af, bf);

    return 0;
}