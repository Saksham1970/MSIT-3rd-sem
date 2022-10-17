#include <stdio.h>

int array[100];
int top1 = -1, bottom2 = 100, size = 100;

int main()
{

    return 0;
}

void push1(int element)
{
    if (bottom2 - top1 > 1)
    {
        top1++;
        array[top1] = element;
    }
    else
        printf("Stack Overflow\n");
}

void push2(int element)
{
    if (bottom2 - top1 > 1)
    {
        bottom2--;
        array[bottom2] = element;
    }
    else
        printf("Stack Overflow\n");
}

int pop1()
{
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

    printf("Stack1: \n");
    for (int i = top1; i >= 0; i--)
    {
        printf("%d\n", i);
    }
}

void print_stack_2()
{

    printf("Stack1: \n");
    for (int i = size - 1; i >= bottom2; i++)
    {
        printf("%d\n", i);
    }
}
