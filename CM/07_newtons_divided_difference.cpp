#include <iostream> // Header Files
#include <algorithm>

// Prototyping the functions
float newton_divided_difference(float, float *, float *, int);

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
    std::cout << "Y for the value " << x << " is " << newton_divided_difference(x, x_array, y_array, n);

    // Freeing the arrays
    delete x_array;
    delete y_array;

    return 0;
}

float newton_divided_difference(float x, float *x_array, float *y_array, int n)
{

    // Function used to find the value of y for a given x using the newton's divided difference formula
    // returns the value of y as a float

    // y dels stores the values of the divided differences which are needed for calculation
    float *y_dels = new float[n];

    // y new is a copy of y array and is used to find divided differences
    float *y_new = new float[n];
    std::copy(y_array, y_array + n, y_new);

    // for loop to find divided differences and store the top most value in y dels which is used in calculating actual value
    for (int i = 0; i < n; i++)
    {
        y_dels[i] = y_new[0];
        for (int j = 0; j < n - i - 1; j++)
            y_new[j] = (y_new[j + 1] - y_new[j]) / (x_array[j + i + 1] - x_array[j]);
    }

    // Delete y_new coz no longer used
    delete y_new;

    // Newtons's divided difference formula being applied
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        int y_term = 1;
        for (int j = 0; j < i; j++)
            y_term *= (x - x_array[j]);
        y_term *= y_dels[i];
        y += y_term;
    }

    // Freeing y_dels
    delete y_dels;

    // Returning y
    return y;
}