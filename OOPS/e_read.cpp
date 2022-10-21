#include <iostream> // Header files

// Driver code
int main()
{
    // Inputting the variables
    float a, b, c, x;
    std::cout << "Enter the value of a: ";
    std::cin >> a;
    std::cout << "Enter the value of b: ";
    std::cin >> b;
    std::cout << "Enter the value of c: ";
    std::cin >> c;
    
    // Outputting the answer
    x = a / (b - c);
    std::cout << "Value of x is: " << x;

    return 0;
}