#include <iostream> // Header Files

// Template declaration
template <class number>

class Number
{

private:
    number *_value;

public:
    // Constructor
    Number(number value)
    {
        printf("Constructor Called!\n");
        this->_value = new number;
        *(this->_value) = value;
    }

    // Default Constructor
    Number()
    {
        printf("Default Constructor Called!\n");
        this->_value = new number;
        *(this->_value) = 0;
    }

    // Copy Constructor
    Number(const Number &other)
    {
        printf("Copy Constructor Called!\n");
        this->_value = new number;
        *(this->_value) = *(other._value);
    }

    // Copy Assignment Operator
    Number &operator=(const Number &other)
    {
        printf("Copy Assignment Called!\n");
        *(this->_value) = *(other._value);
        return *this;
    }

    // Move Constructor
    Number(Number &&other)
    {
        printf("Move Constructor Called!\n");
        this->_value = other._value;
        other._value = nullptr;
    }

    // Move Assignment Operator
    Number &operator=(Number &&other)
    {
        printf("Move Assignment Called!\n");
        this->_value = other._value;
        other._value = nullptr;
        return *this;
    }

    // Destructor
    ~Number()
    {
        printf("Destructor Called!\n");
        delete this->_value;
    }

    number value() { return *(this->_value); }

    Number operator+(const Number &other)
    {
        return Number(*(this->_value) + *(other._value));
    }

    bool operator>(const Number &other)
    {
        return *(this->_value) > *(other._value);
    }

    // ostream operator overloading for printing
    friend std::ostream &operator<<(std::ostream &output, const Number &num)
    {
        output << *(num._value);
        return output;
    }
};

// Driver Code
int main()
{
    float f1, f2;
    std::cout << "Enter the number 1: ";
    std::cin >> f1;
    std::cout << "Enter the number 2: ";
    std::cin >> f2;
    std::cout << std::endl;

    std::cout << "Demonstration of various special member functions of class: \n";
    std::cout << std::endl;

    std::cout << "Objects A and B (basic constructors): \n";
    Number<float> a(f1); // Constructor
    Number<float> b(f2); // Constructor
    std::cout << std::endl;

    std::cout << "Object C (Defualt constructors): \n";
    Number<float> c; // Default Constructor
    std::cout << std::endl;

    std::cout << "Object D (Move constructor but elision): \n";
    Number<float> d = b + a; // Copy Elision
    std::cout << std::endl;

    std::cout << "Object C = B + A (Move assignment operator): \n";
    c = b + a; // Move Assignment Operator
    std::cout << std::endl;

    std::cout << "Object E (Move constructor): \n";
    Number<float> e = std::move(b + a); // Move Constructor
    std::cout << std::endl;

    std::cout << "Object F (Copy constructor): \n";
    Number<float> f = b; // Copy constructor
    std::cout << std::endl;

    std::cout << "Object C = F (Copy Assignment): \n";
    c = f; // Copy Assignment Operator
    std::cout << std::endl;

    std::cout << "Checking which from A and B is bigger: \n"; // Overloaded > Operator
    std::cout << (a > b ? a.value() : b.value()) << " is bigger\n";
    std::cout << std::endl;
}