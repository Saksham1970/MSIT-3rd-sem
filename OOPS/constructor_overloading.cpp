#include <iostream> // Header files

class Complex
{
    // The class for Complex numbers

private:
    float real_part;
    float imag_part;

public:
    // Constructor with no arguments, sets both values as 0
    Complex()
    {
        this->real_part = 0;
        this->imag_part = 0;
    }

    // Constructor with 1 argument, sets both values as one
    Complex(float value)
    {
        this->real_part = value;
        this->imag_part = value;
    }

    // Constructor with 2 arguments, 1 for each part
    Complex(float real_part, float imag_part)
    {
        this->real_part = real_part;
        this->imag_part = imag_part;
    }

    // + Operator overloading for addition
    Complex operator+(const Complex &other)
    {
        return Complex(this->real_part + other.real_part, this->imag_part + other.imag_part);
    }

    // ostream operator overloading for printing
    friend std::ostream &operator<<(std::ostream &output, const Complex &number)
    {
        output << number.real_part << " + (" << number.imag_part << ")i";
        return output;
    }
};

// Driver code
int main()
{

    // Initialising 3 Complex numbers using each constructor
    Complex A;
    Complex B(2.6);
    Complex C(1.4, 4.5);

    // Printing them and their addition
    std::cout << "A = " << A << ", B = " << B << ", C = " << C << std::endl;
    std::cout << "B+C = " << B + C;

    return 0;
}
