#include<iostream>

float differential_eq(float x, float y){
    return (y * y - x * x) / (y * y + x * x);
}

float runge_kutta(float x0, float y0, float h);

int main()
{
    float h, x0, y0;

    std::cout << "\nEnter x0: ";
    std::cin >> x0;

    std::cout << "\nEnter y0: ";
    std::cin >> y0;

    std::cout << "\nEnter h: ";
    std::cin >> h;

    std::cout << "Y with differential equation (y^2 - x^2)/(y^2 + x^2) at X = "<< x0 + h << " is: " << runge_kutta(x0, y0, h);

    return 0;
}

float runge_kutta(float x0, float y0, float h){
    
    float k1, k2, k3, k4;
    k1 = h * differential_eq(x0, y0);
    k2 = h * differential_eq(x0 + h / 2, y0 + k1 / 2);
    k3 = h * differential_eq(x0 + h / 2, y0 + k2 / 2);
    k4 = h * differential_eq(x0 + h, y0 + k3);
    
    return y0 + (k1 + 2 * k2 + 2 * k3 + k4)/6;
}