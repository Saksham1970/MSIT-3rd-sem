#include <iostream> // Header Files

// Prototyping the functions
float lagranges_interpolation(float, float *, float *, int);

// Driver Code
int main()
{

    // Getting the number of values to be stored
    int n;
    std::cout << "Enter the number of set of values of x and y: ";
    std::cin >> n;

    // Creating new arrays with the size inputted
    float *x_array = new float[n];
    float *y_array = new float[n];

    // Filling the arrays
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the value of x" << i << " :";
        std::cin >> x_array[i];

        std::cout << "Enter the value of y" << i << " :";
        std::cin >> y_array[i];

        std::cout << std::endl;
    }

    // Inputting the x for which y to be found
    float x;
    std::cout << "Enter the value of x for which y to be found out :";
    std::cin >> x;

    // Outputing the value
    std::cout << "Y for the value " << x << " is " << lagranges_interpolation(x, x_array, y_array, n);

    // Freeing the arrays
    delete x_array;
    delete y_array;

    return 0;
}

float lagranges_interpolation(float x, float *x_array, float *y_array, int n)
{

    // Function used to find the value of y for a given x using the lagrange's interpolation formula
    // returns the value of y as a float

    // initialising y to be returned
    float y = 0;

    // Lagrange's interpolation formula being applied
    for (int i = 0; i < n; i++)
    {
        float y_term = 1;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                y_term *= (x - x_array[j]);
                y_term /= (x_array[i] - x_array[j]);
            }
        }
        y_term *= y_array[i];
        y += y_term;
    }

    // Returning y
    return y;
}