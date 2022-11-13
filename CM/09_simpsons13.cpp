#include<iostream> // Header files
#include<limits>
#include<math.h>

float f(float x){
    // Function whose integral to be found

    return exp(-x * x);
}

// Prototyping the function
float simpson_1_3(float a, float b, float h);

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

    // Making sure number is even
    if (n%2 == 1)
    {
        n = n + 1;
        std::cout << "Since n is not even taking n as: " << n << std::endl;
    }

    // Calculating width size
    float h = (b - a) / n;

    // Finding integral using function
    std::cout<< "The integral of the function is: "<< simpson_1_3(a, b, h);
    
    return 0;
}

float simpson_1_3(float a, float b, float h){
    // Function uses simpson 1/3 rule to find the integral of the function
    // It returns the float I which is the integral

    // Initiallising I
    float I = 0;

    // Adding boundary function values
    I += h / 3 * (f(a) + f(b));

    // Adding the rest using loop
    for (int i = 1; a + h * i < b; i++)
        I += ((i %2 == 1) ? 4 : 2)/3.0f * h * (f(a + h * i));

    // Returning integration value
    return I;
}