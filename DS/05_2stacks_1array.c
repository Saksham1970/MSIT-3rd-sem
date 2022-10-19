#include <stdio.h> // Header files

// Defining stack variables
int array[100];
int top1 = -1, bottom2 = 100, size = 100;
// Top 1 is top of stack 1, Bottom 2 is top of the inverted stack 2

// Prototyping the functions
void push1(int);
void push2(int);
int pop1();
int pop2();
void print_stack_1();
void print_stack_2();

// Driver Code
int main()
{

    // Printing the stacks at the start of program
    printf("\nStacks at the start.\n");
    print_stack_1();
    print_stack_2();

    // Pushing 2 elements into stack 1 and printing
    push1(1);
    push1(2);
    printf("\nStack 1 after pushing 2 elements.\n");
    print_stack_1();

    // Pushing 2 elements into stack 2 and printing
    push2(3);
    push2(4);
    printf("\nStack 2 after pushing 2 elements.\n");
    print_stack_2();

    // Popping elements from stack 1
    printf("\nPopping element from stack 1: ");
    printf("%d \n", pop1());
    printf("Popping element from stack 1: ");
    printf("%d \n", pop1());
    printf("Popping element from stack 1: ");
    printf("%d \n", pop1());
    printf("\nStack 1 after popping.\n");
    print_stack_1();

    // Popping elements from stack 2
    printf("\nPopping element from stack 2: ");
    printf("%d \n", pop2());
    printf("Popping element from stack 2: ");
    printf("%d \n", pop2());
    printf("Popping element from stack 2: ");
    printf("%d \n", pop2());
    printf("\nStack 2 after popping.\n");
    print_stack_2();

    return 0;
}

void push1(int element)
{
    // Function to push element into stack 1
    if (bottom2 - top1 > 1) // Checks if space available
    {
        top1++;
        array[top1] = element;
    }
    else
        printf("Stack Overflow\n");
}

void push2(int element)
{
    // Function to push element into stack 2
    if (bottom2 - top1 > 1) // Checks if space available
    {
        bottom2--;
        array[bottom2] = element;
    }
    else
        printf("Stack Overflow\n");
}

int pop1()
{
    // Function to pop and return element from stack 1
    // Checks if elements present
    if (top1 > -1)
    {
        int element = array[top1];
        top1--;
        return element;
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

int pop2()
{
    // Function to pop and return element from stack 2
    // Checks if elements present
    if (bottom2 < size)
    {
        int element = array[bottom2];
        bottom2++;
        return element;
    }
    else
    {
        printf("Stack Underflow\n");
        return -1;
    }
}

void print_stack_1()
{
    // Function to print elements of stack 1
    printf("Stack1: \n");
    for (int i = top1; i >= 0; i--)
    {
        printf("%d\n", array[i]);
    }
}

void print_stack_2()
{
    // Function to print elements of stack 2
    printf("Stack2: \n");
    for (int i = bottom2; i <= size - 1; i++)
    {
        printf("%d\n", array[i]);
    }
}
