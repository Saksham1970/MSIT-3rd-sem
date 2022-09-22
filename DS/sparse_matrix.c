// Header files
#include<stdio.h> 
#include<stdlib.h>

// Struct that will store our non zero data
struct DataElement{
    int value;
    int row;
    int column;
};

// Prototyping the functions
int* input2D_matrix1D(int *, int *);
struct DataElement *shredder(int[], int, int, int *);
void printCompactMatrix(struct DataElement *, int);

int main()
{   
    // Getting a user inputted 2D sparse array that is passed as 1D through the function
    int rows,columns;
    int *sparse_matrix1D = input2D_matrix1D(&rows, &columns);

    // Converting the sparse array into a compact array (array of structure)
    int size;
    struct DataElement *compact_matrix = shredder(sparse_matrix1D, rows, columns, &size);

    // Printing the compact array
    printCompactMatrix(compact_matrix,size);

    return 0;
}

struct DataElement* shredder(int sparse_matrix1D[], int rows, int columns, int* compact_size){
    // This function converts sparse matrix to compact matrix. Returns struct array and array size.

    int(*sparse_matrix)[rows] = (int (*)[rows])sparse_matrix1D; // Converts 1D array into 2D array using typecasting

    // Calculates the number of non-zero elements in the matrix
    int filled_count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (sparse_matrix[i][j] != 0)
                filled_count++;

    // Creates a struct array with length as of the number of non-zero elements
    struct DataElement* compact_matrix = (struct DataElement *)malloc(filled_count * sizeof(struct DataElement));
    
    // Add structs to the struct array
    filled_count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (sparse_matrix[i][j] != 0){
                
                compact_matrix[filled_count].value = sparse_matrix[i][j];
                compact_matrix[filled_count].row = i;
                compact_matrix[filled_count].column = j;

                filled_count++;
            }

    // Returns the array and its size
    *compact_size = filled_count;
    return compact_matrix;
}

int* input2D_matrix1D(int* rows,int* columns){
    // This function takes input from the user and creates an array from that

    printf("Enter the number of Rows: ");
    scanf("%d",rows);   // It also returns the value back because pointer 
    printf("Enter the number of Columns: ");
    scanf("%d",columns);

    // Creates an array with length as if the 2D matrix was converted to 1D row wise
    // This is done since you cannot return a variable length multidimensional array 
    int* matrix = (int*)malloc((*rows) * (*columns) * sizeof(int));

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++){
            printf("Enter the number at position (%d,%d): ", i,j);
            scanf("%d",matrix + i*(*columns) + j);
        }

    return matrix;
}

void printCompactMatrix(struct DataElement* matrix,int size){
    // Prints the compact matrix using a for loop
    printf("\nCompact Matrix \n");
    for (int i = 0; i < size; i++)
        printf("Element No. %d, Value: %d  Row: %d  Column: %d \n", i, matrix[i].value, matrix[i].row, matrix[i].column);
}