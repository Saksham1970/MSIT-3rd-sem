#include <stdio.h>
#include <stdlib.h>

struct Employee
{
    int employee_id;
    char name[30];
    char department[10];
};

struct Node
{
    struct Employee employee;
    struct Node *next;
    struct Node *prev;
};

struct Node *createDummyLinkedList();
void insertStartNode(struct Node *, struct Node *);
void deleteLastNode(struct Node *);
void printLL(struct Node *);

int main()
{

    struct Node *head = createDummyLinkedList();

    printf("Created Linked list: \n\n");
    printLL(head);

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    // Check Overflow
    if (node == NULL)
    {
        printf("OVERFLOW\n");
        return 1;
    }
    struct Employee employee = {14463, "Ritesh Singh", "IT"};
    node->employee = employee;

    insertStartNode(head, node);
    head = node;
    printf("\nLinked list after insterting a employee data at starting: \n\n");
    printLL(head);

    deleteLastNode(head);
    printf("\nLinked list after deleting a employee at the end: \n\n");
    printLL(head);
}

struct Node *createDummyLinkedList()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    // Check for overflow
    if (head == NULL || second == NULL || third == NULL)
    {
        printf("OVERFLOW\n");
        return NULL;
    }

    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = NULL;
    third->prev = second;

    struct Employee emp1 = {14460, "Sunil Shetty", "HR"};
    struct Employee emp2 = {14461, "Rajiv Gandhi", "Accounts"};
    struct Employee emp3 = {14462, "Ajay Devgan", "Admin"};

    head->employee = emp1;
    second->employee = emp2;
    third->employee = emp3;

    return head;
}

void deleteLastNode(struct Node *head)
{

    struct Node *currentnode = head;

    // checks for if the list is empty (UNDERFLOW)
    if (currentnode == NULL)
        return currentnode;

    while (currentnode->next != NULL)
        currentnode = currentnode->next;

    currentnode->prev->next = NULL;
    free(currentnode);
}

void insertStartNode(struct Node *head, struct Node *node)
{
    node->prev = NULL;
    node->next = head;
    head->prev = node;
}

void printLL(struct Node *head)
{

    struct Node *currentnode = head;

    while (currentnode != NULL)
    {
        printf("Employee ID: %d Name: %s Department: %s \n", currentnode->employee.employee_id, currentnode->employee.name, currentnode->employee.department);
        currentnode = currentnode->next;
    }
}