#include <stdio.h> // Header files
#include <stdlib.h>

// Struct that actually holds the information
struct College
{
    int college_id;
    char name[30];
};

// Node struct of the linked list
struct Node
{
    struct College college;
    struct Node *next;
};

// Prototyping the functions
struct Node *createDummyLinkedList();
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

    // Check Overflow
    if (node == NULL)
    {
        printf("OVERFLOW\n");
        return 1;
    }

    struct College college = {14463, "IITD"};
    node->college = college;

    insertStartNode(head, node);
    head = node;
    printf("\nLinked list after insterting a college data at starting: \n\n");
    printLL(head);

    deleteLastNode(head);
    printf("\nLinked list after deleting a college at the end: \n\n");
    printLL(head);

    return 0;
}

void deleteLastNode(struct Node *head)
{
    struct Node *temp = head;

    // checks for if the list is empty (UNDERFLOW)
    if (temp == NULL)
        return temp;

    while (1)
    {
        if (temp->next->next == head)
        {
            free(temp->next);
            temp->next = head;
            break;
        }
        temp = temp->next;
    }
}

void insertStartNode(struct Node *head, struct Node *node)
{
    node->next = head;
    struct Node *temp = head;
    while (1)
    {
        if (temp->next == head)
        {
            temp->next = node;
            break;
        }
        temp = temp->next;
    }
}

struct Node *createDummyLinkedList()
{
    // Creating a dummy list to do our operations on

    // Allocating memory for our variables
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    // Check Overflow
    if (head == NULL || second == NULL || third == NULL)
    {
        printf("OVERFLOW\n");
        return NULL;
    }

    // linking the list
    head->next = second;
    second->next = third;
    third->next = head;

    // Creating information
    struct College college1 = {14460, "MSIT"};
    struct College college2 = {14461, "NSUT"};
    struct College college3 = {14462, "DTU"};

    // Assigning information
    head->college = college1;
    second->college = college2;
    third->college = college3;

    // Returning head
    return head;
}

void printLL(struct Node *head)
{
    // Printing the list by traversing
    struct Node *currentnode = head;

    if (head == NULL)
        return;

    do
    {
        printf("College ID: %d Name: %s \n", currentnode->college.college_id, currentnode->college.name);
        currentnode = currentnode->next;

    } while (currentnode == head);
}