// Header Files
#include <iostream>

// Prototyping the functions
int *input2D_matrix1D(int *, int *);
int *AxB(int *, int *, int, int, int);
void print2Dmatrix(int *, int, int);

int main()
{

    // Getting the two matrices A and B inputted
    // A1D namins is used becuase its a 2D array A but in 1D form
    int ARows, ACols, BRows, BCols;
    std::cout << "Input data for Matrix A:" << std::endl;
    int *A1D = input2D_matrix1D(&ARows, &ACols);
    std::cout << "\nInput data for Matrix B:" << std::endl;
    int *B1D = input2D_matrix1D(&BRows, &BCols);

    // Checking if the matrices are valid for being multiplied
    if (ACols != BRows)
    {
        std::cout << "Inputted matrix cant be multiplied.";
        return 0;
    }

    // Multiplication using function
    int *C1D = AxB(A1D, B1D, ARows, ACols, BCols);

    // Printing using function
    print2Dmatrix(C1D, ARows, BCols);

    return 0;
}

int *AxB(int *A, int *B, int ARows, int ACols, int BCols)
{

    // Creating a 2D array with size ARows X BCols
    int(*C)[ARows] = (int(*)[ARows]) new int[ARows * BCols];

    // Matrix multiplication logic
    for (int i = 0; i < ARows; i++)
        for (int j = 0; j < BCols; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < ACols; k++)
                C[i][j] += *(A + ACols * i + k) * *(B + ACols * k + j);
        }
    return (int *)C;
}

int *input2D_matrix1D(int *rows, int *columns)
{
    // This function takes input from the user and creates an array from that

    printf("Enter the number of Rows: ");
    scanf("%d", rows); // It also returns the value back because pointer
    printf("Enter the number of Columns: ");
    scanf("%d", columns);

    // Creates an array with length as if the 2D matrix was converted to 1D row wise
    // This is done since you cannot pass in function and return a variable length multidimensional array
    int *matrix = new int[(*rows) * (*columns)];

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++)
        {
            printf("Enter the number at position (%d,%d): ", i, j);
            scanf("%d", matrix + i * (*columns) + j);
        }

    return matrix;
}

void print2Dmatrix(int *A1D, int rows, int columns)
{

    // Converting 1D array into 2D array using type casting
    int(*A)[rows] = (int(*)[rows])A1D;

    std::cout << "\nMatrix C = AxB:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            std::cout << "\t" << A[i][j];
        std::cout << "\n";
    }
}