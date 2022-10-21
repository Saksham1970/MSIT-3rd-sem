#include <iostream> // Header files

// Function to find if the number if prime
bool is_prime(int num)
{
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}

// Driver code
int main()
{
    // Inputtint the number
    int num;
    std::cout << "Input the number to be checked if its prime: ";
    std::cin >> num;
    
    // Ouputting if prime
    std::cout << "The number " << num << (is_prime(num) ? (" is prime") : (" is not prime"));
    
    return 0;
}