#include <stdio.h> //header files
#include <math.h>

float fx(float); // function prototyping
void get_initial_guesses(float *, float *);
float bisection(float *, float *);

int main()
{
    float a, b, m;
    float max_error;
    get_initial_guesses(&a, &b);
    printf("Input the maximum error allowed: ");
    scanf("%f", &max_error);
    float error;
    int itr = 0;
    while (1)
    {
        itr++;
        m = (a + b) / 2;
        printf("Iteration No: %d, a: %f, b %f, m:%f \n", itr, a, b, m);
        error = bisection(&a, &b);
        if (max_error > error)
            break;
    }
    printf("The value of zero of function x^3 - 4x -9 is at %f with error within %f with the number of %d iterations.", m, error, itr);
    return 0;
}

float fx(float x)
{ // the mathematical function used
    return (pow(x, 3) - 4 * x - 9);
}

void get_initial_guesses(float *a, float *b)
{
    *a = 0;
    float i = 1;
    float fx_a = fx(*a);
    while (1)
    {
        if (fx_a * fx(i) < 0)
        { // Checks for values near 0, satisfying the inequality for a & b
            *a = i - 1;
            *b = i;
            break;
        }
        if (fx_a * fx(-i) < 0)
        {
            *a = i + 1;
            *b = -i;
            break;
        }
        i++;
    }
}

float bisection(float *a, float *b)
{
    float m = (*a + *b) / 2;
    float fx_a = fx(*a);
    float fx_b = fx(*b);
    float fx_m = fx(m);
    if (fx_a * fx_m > 0) // checking for same sign
        *a = m;
    else
        *b = m;
    return fabs(*a - *b); // error
}
