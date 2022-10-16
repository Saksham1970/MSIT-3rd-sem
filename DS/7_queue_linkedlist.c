#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;  
};
struct Node* bottom = NULL;
struct Node *top = NULL;

void insert(int element){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Overflow\n");
        return;
    }
    newNode->data = element;
    newNode->next = NULL;
    if (bottom == NULL)
        bottom = top = newNode;
    else{
    top->next = newNode;
    top = newNode;
    }
}

int delete() {
    if (bottom == NULL) {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        struct Node *temp = bottom;
        int element = bottom->data; //to store data of top node
        bottom = bottom->next; 
        if (bottom == NULL)
            top == bottom;
        free(temp); // deleting the node
        return element;
    }
}


void display() {

    // Printing the list by traversing
    struct Node *currentnode = bottom;
    while (currentnode != NULL)
    {
        printf("%d ,", currentnode->data);
        currentnode = currentnode->next;
    }
    printf("\n");
}