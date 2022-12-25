// Header Files
#include <iostream>

// Prototyping the functions
float *input2D_matrix1D(int *);
void gauss_jordan(float *, int);
void print2Dmatrix(float *, int);

int main()
{

    // Getting the matrix inputted
    // A1D naming is used becuase its a 2D array A but in 1D form
    int order;
    std::cout << "Input data for Matrix:" << std::endl;
    float *A1D = input2D_matrix1D(&order);

    gauss_jordan(A1D, order);

    // Printing using function
    print2Dmatrix(A1D, order);

    return 0;
}

float *input2D_matrix1D(int *order)
{
    // This function takes input from the user and creates an array from that

    printf("Enter the order of square matrix: ");
    scanf("%d", order); // It also returns the value back because pointer

    // Creates an array with length as if the 2D matrix was converted to 1D row wise
    // This is done since you cannot pass in function and return a variable length multidimensional array
    float *matrix = new float[(*order) * (*order) * 2]; // Creating augumented matrix

    for (int i = 0; i < *order; i++)
        for (int j = 0; j < *order; j++)
        {
            printf("Enter the number at position (%d,%d): ", i, j);
            scanf("%f", matrix + i * (*order * 2) + j);
        }

    // Adding the Identity augumented matrix half

    for (int i = 0; i < *order; i++)
        for (int j = *order; j < *order * 2; j++)
        {
            if (j - *order == i)
                *(matrix + i * (*order * 2) + j) = 1;
            else
                *(matrix + i * (*order * 2) + j) = 0;
        }

    return matrix;
}
void gauss_jordan(float *A1D, int order)
{
    // This method is used for converting augumented matrix to inverse augumented matrix

    // Converting 1D array into 2D array using type casting
    float(*A)[order * 2] = (float(*)[order * 2]) A1D;

    // Main loop to convert each diagonal of matrix to 1 and rest to 0
    for (int i = 0; i < order; i++)
    {
        float temp = A[i][i];
        for (int j = 0; j < 2 * order; j++)
            A[i][j] /= temp;
        for (int k = 0; k < order; k++)
            if (k != i)
            {
                temp = A[k][i];
                for (int j = 0; j < 2 * order; j++)
                    A[k][j] -= A[i][j] * temp;
            }
    }
}

void print2Dmatrix(float *A1D, int order)
{
    //This function prints the second half of augumented matrix

    // Converting 1D array into 2D array using type casting
    float(*A)[2 * order] = (float(*)[2 * order]) A1D;

    std::cout << "\nA Inverse:\n";

    for (int i = 0; i < order; i++)
    {
        for (int j = order; j < 2 * order; j++)
            std::cout << "\t" << A[i][j];
        std::cout << "\n";
    }
}
