#include <iostream>
#include <math.h>
using namespace std;

// An example function whose solution is determined using
// Newton Raphson method. The function is x^3 - 3x^2  - 1
float func(float x)
{
    return x * x * x - 3 * x * x - 1;
}

// Derivative of the above function which is 3*x^x - 6*x
float derivFunc(float x)
{
    return 3 * x * x - 6 * x;
}

// Function to find the root
void newtonRaphson(float x, float error)
{
    float x_old;
    int itr = 1;
    do
    {
        x_old = x;
        if (derivFunc(x) == 0)
        {
            cout << "The value of root cant be found at x = " << x;
            return;
        }
    
        // x(i+1) = x(i) - f(x) / f'(x)
        x = x - func(x) / derivFunc(x);


        cout << "Iteration No.: " << itr << " Value of x: " << x << endl;
        itr++;

    } while (fabs(x - x_old) >= error);

    cout << "The value of the root of equation x^3 - 3x^2  - 1 is : " << x;
}

// Driver program to test above
int main()
{
    float x, error;
    cout << "Input the value of initial x for equation x^3 - 3x^2  - 1 :";
    cin >> x;
    cout << "Input the value of tolerance error :";
    cin >> error;

    newtonRaphson(x, error);
    return 0;
}

/*
OUTPUT

PASS CASE
Input the value of initial x for equation x^3 - 3x^2  - 1 :-20
Input the value of tolerance error :0.000001
Iteration No.: 1 Value of x: -13.0295
Iteration No.: 2 Value of x: -8.39568
Iteration No.: 3 Value of x: -5.3241
Iteration No.: 4 Value of x: -3.29854
Iteration No.: 5 Value of x: -1.97244
Iteration No.: 6 Value of x: -1.10691
Iteration No.: 7 Value of x: -0.522256
Iteration No.: 8 Value of x: -0.0261017
Iteration No.: 9 Value of x: 6.28992
Iteration No.: 10 Value of x: 4.69437
Iteration No.: 11 Value of x: 3.7367
Iteration No.: 12 Value of x: 3.2597
Iteration No.: 13 Value of x: 3.11687
Iteration No.: 14 Value of x: 3.10391
Iteration No.: 15 Value of x: 3.1038
Iteration No.: 16 Value of x: 3.1038
The value of the root of equation x^3 - 3x^2  - 1 is : 3.1038

FAIL CASE
Input the value of initial x for equation x^3 - 3x^2  - 1 :2
Input the value of tolerance error :0.000001
The value of root cant be found at x = 2

*/