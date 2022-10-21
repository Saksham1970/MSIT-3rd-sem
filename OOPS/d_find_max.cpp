#include<iostream>

// Template function for finding max
template<class number> 
number max(number a, number b, number c) { return (a > b) ? (a > c ? a : c) : (c > b ? c : b); }

int main(){

    // Inputting the three numbers
    float a, b, c;
    std::cout << "Enter the value of Number 1: ";
    std::cin >> a;
    std::cout << "Enter the value of Number 2: " ;
    std::cin >> b;
    std::cout << "Enter the value of Number 3: " ;
    std::cin >> c;

    // Outputting the maximum
    std::cout << "Maximum is: " << max(a,b,c);

    return 0;
}