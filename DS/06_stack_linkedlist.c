#include <stdio.h> // Header files
#include <stdlib.h>

// Node struct of the linked list
struct Node
{
    int data;
    struct Node *next;
};
// Top of the stack
struct Node *top = NULL;

// Prototyping the functions
void push(int);
int pop();
int peek();
void display();

// Driver code
int main()
{
    // Printing the stack at the start of program
    printf("\nStack at the start:\n");
    display();
    
    // Pushing 2 elements into stack and printing
    push(1);
    push(2);
    printf("\nStack after pushing 2 elements:\n");
    display();

    // Peeking stack and printing the stack to see changes due to peeking
    printf("\nPeeking stack: ");
    printf("%d \n", peek());
    printf("\nStack after peeking:\n");
    display();


    // Popping stack and printing the stack to see changes due to popping
    printf("\nPopping element from stack: ");
    printf("%d \n", pop());
    printf("\nStack after popping:\n");
    display();
    
    printf("\nPeeking stack: ");
    printf("%d \n", peek());
    printf("Popping element from stack: ");
    printf("%d \n", pop());
    printf("Peeking stack: ");
    printf("%d \n", peek());
    printf("Popping element from stack: ");
    printf("%d \n", pop());
    printf("\nStack after popping:\n");
    display();

    return 0;
}

void push(int element)
{
    // Function to push element into stack

    // Create new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)// Check Overflow
    {   
        printf("Overflow\n");
        return;
    }

    // Set data to the node
    newNode->data = element;
    newNode->next = NULL;

    // replacing the top
    newNode->next = top;
    top = newNode;
}

int pop()
{   
    // Function to pop and return element from stack
    // Checks if elements present
    if (top == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        struct Node *temp = top;
        int element = top->data; // to store data of top node
        top = top->next;
        free(temp); // deleting the node
        return element;
    }
}

int peek()
{
    // Function to peek and return element from stack 1
    // Checks if elements present
    if (top == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else
        return top->data;
}

void display()
{
    // Printing the list by traversing
    struct Node *currentnode = top;

    while (currentnode != NULL)
    {
        printf("%d\n", currentnode->data);
        currentnode = currentnode->next;
    }
}