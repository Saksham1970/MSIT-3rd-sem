#include <stdio.h> // Header files
#include <stdlib.h>

// Struct that actually holds the information
struct Employee
{
    int employee_id;
    char name[30];
    char department[10];
};

// Node struct of the linked list
struct Node
{
    struct Employee employee;
    struct Node *next;
    struct Node *prev;
};

// Prototyping the functions
struct Node *createDummyLinkedList();
struct Node *insertStartNode(struct Node *, struct Node *);
struct Node *deleteLastNode(struct Node *);
void printLL(struct Node *);

// Driver code
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

    struct Employee employee = {14463, "Ritesh Singh", "IT"};
    node->employee = employee;

    // Inserting a Node at the starting
    head = insertStartNode(head, node);
    printf("\nLinked list after insterting a employee data at starting: \n\n");
    printLL(head);

    // Deleting a Node at the ending
    head = deleteLastNode(head);
    printf("\nLinked list after deleting a employee at the end: \n\n");
    printLL(head);

    return 0;
}

struct Node *createDummyLinkedList()
{
    // Creating a dummy list to do our operations on

    // Allocating memory for our variables
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    // Check for overflow
    if (head == NULL || second == NULL || third == NULL)
    {
        printf("OVERFLOW\n");
        return NULL;
    }

    // linking the list
    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = NULL;
    third->prev = second;

    // Creating information
    struct Employee emp1 = {14460, "Sunil Shetty", "HR"};
    struct Employee emp2 = {14461, "Rajiv Gandhi", "Accounts"};
    struct Employee emp3 = {14462, "Ajay Devgan", "Admin"};

    // Assigning information
    head->employee = emp1;
    second->employee = emp2;
    third->employee = emp3;

    // Returning head
    return head;
}

struct Node *deleteLastNode(struct Node *head)
{
    // This function deletes the node at the ending

    struct Node *currentnode = head;

    // checks for if the list is empty (UNDERFLOW)
    if (currentnode == NULL)
        return head;

    // Traverses to the end of the list
    while (currentnode->next != NULL)
        currentnode = currentnode->next;

    // Breaking the prev nodes link to this node
    currentnode->prev->next = NULL;

    // Freeing this memory
    free(currentnode);

    return head;
}

struct Node *insertStartNode(struct Node *head, struct Node *node)
{
    // This function inserts node at the starting of the list
    node->prev = NULL;
    node->next = head;
    head->prev = node;
    return node;
}

void printLL(struct Node *head)
{
    // Printing the list by traversing
    struct Node *currentnode = head;

    while (currentnode != NULL)
    {
        printf("Employee ID: %d Name: %s Department: %s \n", currentnode->employee.employee_id, currentnode->employee.name, currentnode->employee.department);
        currentnode = currentnode->next;
    }
}