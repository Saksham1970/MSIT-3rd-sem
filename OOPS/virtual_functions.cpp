#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class List
{
protected:
    Node *head = NULL;
    Node *tail = NULL;

public:
    virtual void store(int n);
    virtual int retrive();
};

class Stack : public List
{
public:
    void store(int num)
    {
        Node *n1 = new Node;
        n1->data = num;
        n1->next = NULL;

        if ((this->head == NULL) && (this->tail == NULL))
        {
            this->head = n1;
            this->tail = n1;
        }
        else
        {
            this->tail->next = n1;
            this->tail = n1;
        }
    }
    int retrive()
    {
        if ((this->tail == NULL) && (this->head == NULL))
        {
            return -1;
        }
        else
        {
            int n = this->tail->data;
            Node *ptr = this->head;
            while ((ptr->next != this->tail) && (this->head != this->tail))
            {
                ptr = ptr->next;
            }
            ptr->next = NULL;
            free(this->tail);
            if (this->head != this->tail)
            {
                this->tail = ptr;
            }
            else
            {
                this->tail = NULL;
                this->head = NULL;
            }
            return n;
        }
    }

    // ostream operator overloading for printing
    friend std::ostream &operator<<(std::ostream &output, const Stack &stack)
    {
        Node *ptr = stack.head;
        while (ptr!=NULL){
            output << ptr->data << std::endl;
            ptr = ptr->next;
        }
        return output;
    }
};

class Queue : public List
{
public:
    void store(int n)
    {
        Node *n1 = new Node;
        n1->data = n;
        n1->next = NULL;

        if ((this->head == NULL) && (this->tail == NULL))
        {
            this->head = n1;
            this->tail = n1;
        }
        else
        {
            this->tail->next = n1;
            this->tail = n1;
        }
    }
    int retrive()
    {
        if ((this->tail == NULL) && (this->head == NULL))
        {
            return -1;
        }
        else
        {
            int n = this->head->data;
            if (this->head == this->tail)
            {
                this->head = this->tail = NULL;
            }
            else
            {
                this->head = this->head->next;
            }
            return n;
        }
    }
    // ostream operator overloading for printing
    friend std::ostream &operator<<(std::ostream &output, const Queue &queue)
    {
        Node *ptr = queue.head;
        while (ptr!=NULL){
            output << ptr->data << std::endl;
            ptr = ptr->next;
        }
        return output;
    }
};

int main()
{
    Stack S;
    Queue Q;
    std::cout << "Stack: " << std::endl;
    std::cout << S;
    S.store(10);
    S.store(20);
    std::cout << "After Storing twice Stack: " << std::endl;
    std::cout << S;
    std::cout << "Retriving once: " << S.retrive() << std::endl;
    std::cout << "Retriving twice: " << S.retrive() << std::endl;
    std::cout << "Retriving thrice: " << S.retrive() << std::endl;

    std::cout << "Queue: " << std::endl;
    std::cout << Q;
    S.store(30);
    S.store(40);
    std::cout << "After Storing twice Queue: " << std::endl;
    std::cout << Q;
    std::cout << "Retriving once: " << Q.retrive() << std::endl;
    std::cout << "Retriving twice: " << Q.retrive() << std::endl;
    std::cout << "Retriving thrice: " << Q.retrive() << std::endl;
    
    return 0;
}