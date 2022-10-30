// C++ Program to find root of an
// equations using secant method
#include <iostream>
#include <math.h>
using namespace std;

// function takes value of x and returns f(x)
float f(float x)
{
    // we are taking equation as cos(x) - x*e^x
    return cos(x) - x * (exp(x));
}

void secant(float x1, float x2, float E)
{
    float itr = 1, x3 = x2;
    x2 = x1;
    do
    {

        // update the value of interval
        x1 = x2;
        x2 = x3;

        if ((f(x2) - f(x1)) == 0)
        {
            cout << "The value of root cant be found.";
            return;
        }

        // calculate the intermediate value
        x3 = x2 - ((x2 - x1) * f(x2)) / (f(x2) - f(x1));

        cout << "n= " << itr + 2 << " Value of x: " << x3 << endl;

        // update number of iteration
        itr++;

    } while (fabs(x3 - x2) >= E); // repeat the loop
                                  // until the convergence

    cout << "Root of the given equation= " << x3 << endl;
}

// Driver code
int main()
{
    float x1, x2, error;
    cout << "Input the value of initial x1 for equation cos(x) - x*e^x :";
    cin >> x1;
    cout << "Input the value of initial x2 for equation cos(x) - x*e^x :";
    cin >> x2;
    cout << "Input the value of tolerance error :";
    cin >> error;
    secant(x1, x2, error);
    return 0;
}

/*
OUTPUT

PASS CASE
Input the value of initial x1 for equation cos(x) - x*e^x :0
Input the value of initial x2 for equation cos(x) - x*e^x :1
Input the value of tolerance error :0.00005
n= 3 Value of x: 0.314665
n= 4 Value of x: 0.446728
n= 5 Value of x: 0.531706
n= 6 Value of x: 0.516904
n= 7 Value of x: 0.517747
n= 8 Value of x: 0.517757
Root of the given equation= 0.517757

FAIL CASE
Input the value of initial x1 for equation cos(x) - x*e^x :0
Input the value of initial x2 for equation cos(x) - x*e^x :0
Input the value of tolerance error :0.00005
The value of root cant be found.


*/