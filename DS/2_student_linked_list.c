#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll_no;
    char name[30];
    char class_sec[5];
};

struct Node
{
    struct Student student;
    struct Node *next;
};

struct Node *createDummyLinkedList();
struct Node *reverseLoop(struct Node *);
struct Node *reverseRecursion(struct Node *);
void deleteNode(struct Node *, int);
void insertNode(struct Node *, struct Node *, int);
void printLL(struct Node *);

int main()
{

    struct Node *head = createDummyLinkedList();

    printf("Created Linked list: \n\n");
    printLL(head);

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    struct Student student = {14463, "Ritesh Singh", "11-B"};
    node->student = student;

    insertNode(head, node, 2);
    printf("\nLinked list after insterting a student data at index 2: \n\n");
    printLL(head);

    deleteNode(head, 14461);
    printf("\nLinked list after deleting a student with roll number 14461: \n\n");
    printLL(head);

    head = reverseLoop(head);
    printf("\nReversed Linked list through loop: \n\n");
    printLL(head);

    head = reverseRecursion(head);
    printf("\nReversed Linked list through recursion: \n\n");
    printLL(head);

    return 0;
}

struct Node *reverseLoop(struct Node *head)
{

    if ((head == NULL) || (head->next == NULL))
    {
        return head;
    }

    struct Node *currentnode = head;
    struct Node *secondnode = head->next;
    struct Node *thirdnode = head->next->next;
    currentnode->next = NULL;

    while (secondnode != NULL)
    {
        thirdnode = secondnode->next;
        secondnode->next = currentnode;
        currentnode = secondnode;
        secondnode = thirdnode;
    }
    return currentnode;
}

struct Node *reverseRecursion(struct Node *head)
{
    if ((head == NULL) || (head->next == NULL))
        return head;

    struct Node *new_head = reverseRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

void deleteNode(struct Node *head, int roll_no)
{
    struct Node *currentnode = head;

    while (currentnode->next != NULL)
    {
        if (currentnode->next->student.roll_no == roll_no)
        {
            struct Node *secondnode = currentnode->next;
            currentnode->next = secondnode->next;
            free(secondnode);
        }
        currentnode = currentnode->next;
    }
}

void insertNode(struct Node *head, struct Node *node, int index)
{
    struct Node *lastnode = NULL;
    struct Node *nextnode = head;

    for (int i = 0; i < index; i++)
    {
        if (nextnode == NULL)
        {
            break;
        }
        lastnode = nextnode;
        nextnode = nextnode->next;
    }
    lastnode->next = node;
    node->next = nextnode;
}

struct Node *createDummyLinkedList()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));

    head->next = second;
    second->next = third;
    third->next = NULL;

    struct Student student1 = {14460, "Sunil Shetty", "6-B"};
    struct Student student2 = {14461, "Rajiv Gandhi", "7-F"};
    struct Student student3 = {14462, "Ajay Devgan", "12-D"};

    head->student = student1;
    second->student = student2;
    third->student = student3;

    return head;
}

void printLL(struct Node *head)
{

    struct Node *currentnode = head;

    while (currentnode != NULL)
    {
        printf("Roll No: %d Name: %s Class: %s \n", currentnode->student.roll_no, currentnode->student.name, currentnode->student.class_sec);
        currentnode = currentnode->next;
    }
}