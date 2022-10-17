// Header Files
#include <iostream>

// Prototyping the functions
int *input2D_matrix1D(int *, int *);
int *AplusB(int *, int *, int, int);
int *transpose(int *, int, int);
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
    if ((ACols != BCols) || (ARows != BRows))
    {
        std::cout << "Inputted matrix cant be Added.";
        return 0;
    }

    // Addition using function
    int *C1D = AplusB(A1D, B1D, ARows, ACols);

    // Transpose using function
    int *At1D = transpose(A1D, ARows, ACols);
    int *Bt1D = transpose(B1D, BRows, BCols);

    // Printing using function
    std::cout << "\nMatrix C = A + B:\n";
    print2Dmatrix(C1D, ARows, ACols);

    std::cout << "\nTranspose A:\n";
    print2Dmatrix(At1D, ACols, ARows);

    std::cout << "\nTranspose B:\n";
    print2Dmatrix(Bt1D, BCols, BRows);

    return 0;
}

int *AplusB(int *A, int *B, int Rows, int Cols)
{

    // Creating a 2D array with size Rows X Cols
    int(*C)[Cols] = (int(*)[Cols]) new int[Rows * Cols];

    // Matrix addition logic
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
        {
            C[i][j] = *(A + Cols * i + j) + *(B + Cols * i + j);
            std::cout << &C[i][j] << std::endl;
        }

    return (int *)C;
}

int *transpose(int *A, int Rows, int Cols)
{

    // Creating a 2D array with size Rows X Cols
    int(*C)[Rows] = (int(*)[Rows]) new int[Rows * Cols];

    // Matrix transpose logic
    for (int i = 0; i < Rows; i++)
        for (int j = 0; j < Cols; j++)
        {
            C[j][i] = *(A + Cols * i + j);
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
    int(*A)[columns] = (int(*)[columns])A1D;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            std::cout << "\t" << A[i][j];
        std::cout << "\n";
    }
}
