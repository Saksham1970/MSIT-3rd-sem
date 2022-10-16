#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int element)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Overflow\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    newNode->next = top;
    top = newNode;
}

int pop()
{
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
    if (top == NULL)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        return top->data;
    }
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