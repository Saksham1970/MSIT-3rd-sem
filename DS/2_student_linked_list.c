#include <stdio.h> // Header files
#include <stdlib.h>

// Struct that actually holds the information
struct Student
{
    int roll_no;
    char name[30];
    char class_sec[5];
};

// Node struct of the linked list
struct Node
{
    struct Student student;
    struct Node *next;
};

// Prototyping the functions
struct Node *createDummyLinkedList();
struct Node *reverseLoop(struct Node *);
struct Node *reverseRecursion(struct Node *);
struct Node *deleteNode(struct Node *, int);
struct Node *insertNode(struct Node *, struct Node *, int);
void printLL(struct Node *);

int main()
{

    // Gets a dummy list for us to perform operations on
    struct Node *head = createDummyLinkedList();

    // Prints the dummy list
    printf("Created Linked list: \n\n");
    printLL(head);

    // Creating a new node called "node"
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    struct Student student = {14463, "Ritesh Singh", "11-B"};
    node->student = student;

    // Inserting node at second position and printing the new list
    head = insertNode(head, node, 2);
    printf("\nLinked list after insterting a student data at index 2: \n\n");
    printLL(head);

    // Deleting the node with roll number as 14461 and printing the new list
    deleteNode(head, 14461);
    printf("\nLinked list after deleting a student with roll number 14461: \n\n");
    printLL(head);

    // Reversing the list using a while loop and printing the new list
    head = reverseLoop(head);
    printf("\nReversed Linked list through loop: \n\n");
    printLL(head);

    // Reversing the list using recursion and printing the new list
    head = reverseRecursion(head);
    printf("\nReversed Linked list through recursion: \n\n");
    printLL(head);

    return 0;
}

struct Node *reverseLoop(struct Node *head)
{
    // Reverses the loop using while loop and returns the new head

    // Checks the list for empty or 1 element
    if ((head == NULL) || (head->next == NULL))
    {
        return head;
    }

    struct Node *currentnode = head;
    struct Node *secondnode = head->next;
    struct Node *thirdnode = head->next->next;
    currentnode->next = NULL;

    // This loop reverses the
    // Going on reversing the direction of every element as traversing through it
    while (secondnode != NULL)
    {
        thirdnode = secondnode->next;
        secondnode->next = currentnode;
        currentnode = secondnode;
        secondnode = thirdnode;
    }
    return currentnode; // returning the new head
}

struct Node *reverseRecursion(struct Node *head)
{
    // Reverses the list using recursion

    // Checks if the list is empty or 1D
    if ((head == NULL) || (head->next == NULL))
        return head;

    // It gets the list from n+1 element to the end and points its tail to nth element
    // and returns the list from n to end
    struct Node *new_head = reverseRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

struct Node *deleteNode(struct Node *head, int roll_no)
{
    // Deletes a node with the given roll number

    struct Node *currentnode = head;

    // checks for if the list is empty
    if (currentnode == NULL)
        return currentnode;

    // checks for if the head node needs to be deleted
    if (currentnode->student.roll_no == roll_no)
    {
        struct Node *secondnode = currentnode->next;
        free(currentnode);
        return secondnode;
    }

    // Traversing through the list
    while (currentnode->next != NULL)
    {
        // chceking if  next node has the roll number
        if (currentnode->next->student.roll_no == roll_no)
        {
            // re-pointing the current node to the third node and deleting the next node
            struct Node *secondnode = currentnode->next;
            currentnode->next = secondnode->next;
            free(secondnode);
            break;
        }

        // continues the traversing
        currentnode = currentnode->next;
    }
    return head;
}

struct Node *insertNode(struct Node *head, struct Node *node, int index)
{
    struct Node *lastnode = NULL;
    struct Node *nextnode = head;

    // Loop till the given index elements
    for (int i = 0; i < index; i++)
    {
        // break If reached end
        if (nextnode == NULL)
        {
            break;
        }

        // continue the loop with increment
        lastnode = nextnode;
        nextnode = nextnode->next;
    }

    // if node inserted at beginning
    if (lastnode == NULL)
    {
        node->next = head;
        head = node;
    }

    // inserting node at index
    lastnode->next = node;
    node->next = nextnode;

    // returning head
    return head;
}

struct Node *createDummyLinkedList()
{
    // Creating a dummy list to do our operations on

    // Allocating memory for our variables
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    // linking the list
    head->next = second;
    second->next = third;
    third->next = NULL;

    // Creating information
    struct Student student1 = {14460, "Sunil Shetty", "6-B"};
    struct Student student2 = {14461, "Rajiv Gandhi", "7-F"};
    struct Student student3 = {14462, "Ajay Devgan", "12-D"};

    // Assigning information
    head->student = student1;
    second->student = student2;
    third->student = student3;

    // Returning head
    return head;
}

void printLL(struct Node *head)
{
    // Printing the list by traversing
    struct Node *currentnode = head;

    while (currentnode != NULL)
    {
        printf("Roll No: %d Name: %s Class: %s \n", currentnode->student.roll_no, currentnode->student.name, currentnode->student.class_sec);
        currentnode = currentnode->next;
    }
}