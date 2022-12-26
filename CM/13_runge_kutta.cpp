#include <iostream> // header files

float differential_eq(float x, float y)
{
    // The equation on which runge kutta to be applied
    return (y * y - x * x) / (y * y + x * x);
}

// Function Prototyping
float runge_kutta(float x0, float y0, float h);

// Driver code
int main()
{
    float h, x0, y0;
    int n;

    std::cout << "Differential equation: (y^2 - x^2)/(y^2 + x^2) \n";

    std::cout << "Enter x0: ";
    std::cin >> x0;

    std::cout << "Enter y0: ";
    std::cin >> y0;

    std::cout << "Enter h: ";
    std::cin >> h;

    std::cout << "Enter n: ";
    std::cin >> n;

    // Loop to apply runge kutta method again and again for n iterations
    for (int i = 1; i <= n; i++)
    {
        y0 = runge_kutta(x0, y0, h);
        x0 += h;
        std::cout << "X" << i << "= " << x0 << " Y" << i << "= " << y0 << std::endl;
    }

    return 0;
}

float runge_kutta(float x0, float y0, float h)
{
    // This function applies runge kutta method
    float k1, k2, k3, k4;
    k1 = h * differential_eq(x0, y0);
    k2 = h * differential_eq(x0 + h / 2, y0 + k1 / 2);
    k3 = h * differential_eq(x0 + h / 2, y0 + k2 / 2);
    k4 = h * differential_eq(x0 + h, y0 + k3);

    return y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}
