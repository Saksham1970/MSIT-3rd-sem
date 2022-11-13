#include<iostream> // Header files
#include<limits>
#include<math.h>

float f(float x){
    // Function whose integral to be found

    return exp(-x * x);
}

// Prototyping the function
float simpson_3_8(float a, float b, float h);

// Driver code
int main(){

    // Increasing floats precision in cout to get more precise results
    std::cout.precision(std::numeric_limits<float>::max_digits10);

    // Inputting the boundaries of integration
    float a,b;
    std::cout << "Enter the lower bound of integration for the function:";
    std::cin >> a;
    std::cout << "Enter the upper bound of integration for the function:";
    std::cin >> b;

    // Inputting the number of widths
    int n;
    std::cout << "Enter the number of widths for the function (n):";
    std::cin >> n;

    // Making sure number is multiple of 3
    if (n%3 != 0)
    {
        n = n + 3 - n%3;
        std::cout << "Since n is not even taking n as: " << n << std::endl;
    }

    // Calculating width size
    float h = (b - a) / n;

    // Finding integral using function
    std::cout<< "The integral of the function is: "<< simpson_3_8(a, b, h);
    
    return 0;
}

float simpson_3_8(float a, float b, float h){
    // Function uses simpson 3/8 rule to find the integral of the function
    // It returns the float I which is the integral

    // Initiallising I
    float I = 0;

    // Adding boundary function values
    I += h * 3/8 * (f(a) + f(b));

    // Adding the rest using loop
    for (int i = 1; a + h * i < b; i++)
        I += ((i %3 == 0) ? 2 : 3) * 3 / 8.0f * h * (f(a + h * i));

    // Returning integration value
    return I;
}