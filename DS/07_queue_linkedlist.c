#include <stdio.h> // Header files
#include <stdlib.h>

// Node struct of the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Top and Bottom of the queue, entry from top and exit from bottom
struct Node *bottom = NULL;
struct Node *top = NULL;

// Prototyping the functions
void insert(int);
int delete();
void display();

// Driver code
int main()
{

    // Printing the queue at the start of program
    printf("\nQueue at the start:\n");
    display();

    // Inserting 2 elements into queue and printing
    insert(1);
    insert(2);
    printf("\nQueue after inserting 2 elements:\n");
    display();

    // Deleting 1 element from queue and printing
    printf("\nDeleting element from Queue: ");
    printf("%d \n", delete());
    printf("\nQueue after Deleting:\n");
    display();

    // Deleting all the elements from queue and printing
    printf("Deleting element from Queue: ");
    printf("%d \n", delete());
    printf("Deleting element from Queue: ");
    printf("%d \n", delete());
    printf("\nQueue after Deleting:\n");
    display();

    return 0;
}

void insert(int element)
{
    // Function to insert element into queue

    // Create new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) // Check Overflow
    {
        printf("Overflow\n");
        return;
    }

    // Set data to the node
    newNode->data = element;
    newNode->next = NULL;

    // replacing the top
    if (bottom == NULL)
        bottom = top = newNode;
    else
    {
        top->next = newNode;
        top = newNode;
    }
}

int delete()
{
    // Function to delete and return element from queue
    // Checks if elements present
    // Returns -1 if underflow
    
    if (bottom == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        struct Node *temp = bottom;
        int element = bottom->data; // to store data of top node
        bottom = bottom->next;
        if (bottom == NULL)
            top = bottom;
        free(temp); // deleting the node
        return element;
    }
}

void display()
{
    // Printing the list by traversing
    struct Node *currentnode = bottom;
    while (currentnode != NULL)
    {
        printf("%d ,", currentnode->data);
        currentnode = currentnode->next;
    }
    printf("\n");
}