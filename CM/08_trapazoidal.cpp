#include<iostream> // Header files
#include<limits>

float f(float x){
    // Function whose integral to be found

    return 1 / (1 + x * x);
}

// Prototyping the function
float trapazoidal(float a, float b, float h);

// Driver code
int main(){

    // Increasing floats precision in cout to get precise results
    std::cout.precision(std::numeric_limits<float>::max_digits10);

    // Inputting the boundaries of integration
    float a,b;
    std::cout << "Enter the lower bound of integration for the function:";
    std::cin >> a;
    std::cout << "Enter the upper bound of integration for the function:";
    std::cin >> b;

    // Inputting the number of widths
    float n;
    std::cout << "Enter the number of widths for the function:";
    std::cin >> n;

    // Calculating width size
    float h = (b - a) / n;

    // Finding integral using function
    std::cout<< "The integral of the function is: "<< trapazoidal(a, b, h);
    
    return 0;
}

float trapazoidal(float a, float b, float h){
    // Function uses Trapazoidal rule to find the integral of the function
    // It returns the float I which is the integral

    // Initiallising I
    float I = 0;

    // Adding boundary function values
    I += h/2*(f(a) + f(b));
    
    // Adding the rest using loop
    for (int i = 1; a + h * i < b; i++)
        I += h * (f(a + h * i));

    // Returning integration value
    return I;
}