#include <stdio.h> // Header files
#include <stdlib.h>

// Node struct of the linked list
struct Node
{
    int data;
    struct Node *next;
};

// rear and front of the queue, entry from rear and exit from front
struct Node *front = NULL;
struct Node *rear = NULL;

// Prototyping the functions
void enqueue(int);
int dequeue();
void display();

// Driver code
int main()
{

    // Printing the queue at the start of program
    printf("\nQueue at the start:\n");
    display();

    // enqueuing 2 elements into queue and printing
    enqueue(1);
    enqueue(2);
    printf("\nQueue after enqueuing 2 elements:\n");
    display();

    // dequeuing 1 element from queue and printing
    printf("\ndequeuing element from Queue: ");
    printf("%d \n", dequeue());
    printf("\nQueue after dequeuing:\n");
    display();

    // dequeuing all the elements from queue and printing
    printf("dequeuing element from Queue: ");
    printf("%d \n", dequeue());
    printf("dequeuing element from Queue: ");
    printf("%d \n", dequeue());
    printf("\nQueue after dequeuing:\n");
    display();

    return 0;
}

void enqueue(int element)
{
    // Function to enqueue element into queue

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

    // replacing the rear
    if (front == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    // Function to dequeue and return element from queue
    // Checks if elements present
    // Returns -1 if underflow
    
    if (front == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        struct Node *temp = front;
        int element = front->data; // to store data of rear node
        front = front->next;
        if (front == NULL)
            rear = front;
        free(temp); // deleting the node
        return element;
    }
}

void display()
{
    // Printing the list by traversing
    struct Node *currentnode = front;
    while (currentnode != NULL)
    {
        printf("%d ,", currentnode->data);
        currentnode = currentnode->next;
    }
    printf("\n");
}