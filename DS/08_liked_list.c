#include <stdio.h> // Header files
#include <stdlib.h>

// Struct that actually holds the information
struct Student
{
    int roll_no;
    char const *name;
    char const *class_sec;
};

// Macro for swapping 2 numbers
#define swap(a, b)                \
    {                             \
        struct Student *temp = a; \
        a = b;                    \
        b = temp;                 \
    }

// Prototyping the functions
struct Student **createDummyList(int, int *);
void reverse(struct Student **, int);
void delete(struct Student **, int, int *);
void insert(struct Student **, struct Student *, int, int, int *);
void printList(struct Student **, int, int);

int main()
{
    // Keeping track of elements and size of the array
    int no_of_elements = 0, size = 10;

    // Gets a dummy list for us to perform operations on
    struct Student **list = createDummyList(size, &no_of_elements);

    // Prints the dummy list
    printf("Created list: \n\n");
    printList(list, size, no_of_elements);

    // creating a new student
    struct Student *student = (struct Student *)malloc(sizeof(struct Student));
    // Check overflow
    if (student == NULL)
    {
        printf("OVERFLOW\n");
        return 1;
    }

    // assigning values to the student node
    student->roll_no = 14463;
    student->name = "Ritesh Singh";
    student->class_sec = "11-B";

    // Inserting node at second position and printing the new list
    insert(list, student, 2, size, &no_of_elements);
    printf("\nList after insterting a student data at index 2: \n\n");
    printList(list, size, no_of_elements);

    // Deleting the node with roll number as 14461 and printing the new list
    delete(list, 14461, &no_of_elements);
    printf("\nList after deleting a student with roll number 14461: \n\n");
    printList(list, size, no_of_elements);

    // Reversing the list and printing the new list
    reverse(list, no_of_elements);
    printf("\nReversed list through loop: \n\n");
    printList(list, size, no_of_elements);

    return 0;
}

void reverse(struct Student **list, int n)
{
    // Reversing the array
    for (int i = 0; i < n / 2; i++)
        swap(list[i], list[n - 1 - i]);
}

void insert(struct Student **list, struct Student *student, int index, int size, int *n)
{
    // Inserting element into array

    // If no space available
    if (*n >= size)
    {
        printf("List Overflow");
        return;
    }

    // Copying the elements around and create space
    for (int i = *n - 1; i >= index; i--)
        swap(list[i], list[i + 1]);

    // increase the count of no of elements in array
    *n = *n + 1;

    list[index] = student;
}

void delete(struct Student **list, int roll_no, int *n)
{
    // Removing element from array

    // If no element in list
    if (*n <= 0)
    {
        printf("List Underflow");
        return;
    }

    int index;
    // Finding the index of the roll number
    for (int i = 0; i < *n; i++)
        if (list[i]->roll_no == roll_no)
        {
            index = i;
            break;
        }

    // Copying the elements over the index
    for (int i = index; i < *n - 1; i++)
        swap(list[i], list[i + 1]);

    // Decreasing the count
    *n = *n - 1;
}

struct Student **createDummyList(int size, int *n)
{
    // Creating a dummy list to do our operations on

    // Allocating memory for our variables
    struct Student *student1 = (struct Student *)malloc(sizeof(struct Student));
    struct Student *student2 = (struct Student *)malloc(sizeof(struct Student));
    struct Student *student3 = (struct Student *)malloc(sizeof(struct Student));

    // Check Overflow
    if (student1 == NULL || student2 == NULL || student3 == NULL)
    {
        printf("OVERFLOW\n");
        return NULL;
    }

    char *name;

    // Creating information
    student1->roll_no = 14460;
    student1->name = "Sunil Shetty";
    student1->class_sec = "6-B";

    student2->roll_no = 14461;
    student2->name = "Rajiv Gandhi";
    student2->class_sec = "7-F";

    student3->roll_no = 14462;
    student3->name = "Ajay Devgan";
    student3->class_sec = "12-D";

    struct Student **list = (struct Student **)malloc(size * sizeof(struct Student *));
    list[0] = student1;
    list[1] = student2;
    list[2] = student3;

    *n = 3;
    return list;
}

void printList(struct Student **list, int size, int n)
{
    // if count is greater than size for some reason print till the size only
    if (n > size)
        n = size;

    for (int i = 0; i < n; i++)
        printf("Roll No: %d Name: %s Class: %s \n", list[i]->roll_no, list[i]->name, list[i]->class_sec);
}