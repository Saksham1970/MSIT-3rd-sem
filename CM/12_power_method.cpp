// Header Files
#include <iostream>
#include <math.h>

// Prototyping the functions
float *input2D_matrix1D(int *order, float **eigen_vector);
float power_method(float *A1D, float **eigen_vector, int order, float error);
void print2Dmatrix(float *A1D, float *eigen_vector, float eigen_value, int order);

// Driver code
int main()
{

    // Getting the matrix inputted
    // A1D naming is used becuase its a 2D array A but in 1D form
    int order;
    std::cout << "Input data for Matrix:" << std::endl;
    float *eigen_vector;
    float *A1D = input2D_matrix1D(&order, &eigen_vector);

    // Getting the error tolerance inputted
    float error;
    std::cout << "\nEnter the tolerable error: ";
    std::cin >> error;

    // Finding the eigen vector and eigen value using function
    float eigen_value = power_method(A1D, &eigen_vector, order, error);

    // Printing using function
    print2Dmatrix(A1D, eigen_vector, eigen_value, order);

    return 0;
}

float *input2D_matrix1D(int *order, float **eigen_vector)
{
    // This function takes input from the user and creates an array from that

    printf("Enter the order of square matrix: ");
    scanf("%d", order);

    // Creates an array with length as if the 2D matrix was converted to 1D row wise
    // This is done since you cannot pass in function and return a variable length multidimensional array
    float *matrix = new float[(*order) * (*order)];
    float *vector = new float[*order];

    // Inputting matrix
    printf("\nEnter details of the matrix:\n");
    for (int i = 0; i < *order; i++)
        for (int j = 0; j < *order; j++)
        {
            printf("Enter the number at position (%d,%d): ", i, j);
            scanf("%f", matrix + i * (*order) + j);
        }

    // Inputting eigen vector
    printf("\nEnter details of the initial eigen vector:\n");
    for (int i = 0; i < *order; i++)
    {
        printf("Enter the number at position (%d,0): ", i);
        scanf("%f", vector + i);
    }

    *eigen_vector = vector;
    return matrix;
}

// Function to find max absolute value in the vector (eigen value)
float find_max(float *vector, int order)
{
    float max = vector[0];
    for (int i = 0; i < order; i++)
        if (vector[i] * vector[i] > max * max)
            max = vector[i];
    return max;
}

float power_method(float *A1D, float **eigen_vector, int order, float error)
{

    // This function finds eigen value and eigen vector of a matrix A using power method

    float old_eigen_value = 0; // For checking precision using error inputted
    float eigen_value;
    // Converting 1D array into 2D array using type casting
    float(*A)[order] = (float(*)[order])A1D;

    while (true)
    {

        // Main loop

        // Calculating the product of A and eigen vector
        float *product_vector = new float[order];
        for (int i = 0; i < order; i++)
        {
            float temp = 0;
            for (int j = 0; j < order; j++)
                temp += (*eigen_vector)[j] * A[i][j];
            product_vector[i] = temp;
        }

        // Finding the greatest absolute value and dividing the vector by it
        eigen_value = find_max(product_vector, order);
        for (int i = 0; i < order; i++)
            product_vector[i] /= eigen_value;

        // Changing the vector
        delete (*eigen_vector);
        *eigen_vector = product_vector;

        // If eigen value withing error
        if (isnan(eigen_value) || (old_eigen_value != 0 && fabs(eigen_value - old_eigen_value) < error))
            break;
        else
            old_eigen_value = eigen_value;
    }

    return eigen_value;
}

void print2Dmatrix(float *A1D, float *eigen_vector, float eigen_value, int order)
{
    // This function prints the matrix, eigen vector and eigen value using loops

    // Converting 1D array into 2D array using type casting
    float(*A)[order] = (float(*)[order])A1D;

    std::cout << "\nA:\n";

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
            std::cout << "\t" << A[i][j];
        std::cout << "\n";
    }

    std::cout << "\nEigen Vector:\n";

    for (int i = 0; i < order; i++)
        std::cout << "\t" << eigen_vector[i] << "\n";

    std::cout << "\nEigen Value: " << eigen_value;
}
