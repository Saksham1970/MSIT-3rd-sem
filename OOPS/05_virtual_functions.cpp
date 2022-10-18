#include <iostream> // Header Files

// Node struct as data element of a list/stack/queue, using concept of linked list
struct Node
{
    int data;
    Node *next;
};

// Parent Class list
class List
{
protected:

    // Protected to be inherited
    Node *head = NULL;
    Node *tail = NULL;

public:

    // Virtual for overriding in derived class
    virtual void store(int n) = 0;  // Pure virtual functions since assigned to 0
    virtual int retrive() = 0;
};

// Derived Class Stack from Class List
class Stack : public List
{
public:

    // Overriding the virtual functions of class List
    void store(int num)
    {

        // Stack Push Logic

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

        // Stack Pop Logic

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
        // Printing by Linked list traversing

        Node *ptr = stack.head;
        while (ptr != NULL)
        {
            output << ptr->data << std::endl;
            ptr = ptr->next;
        }
        return output;
    }
};

// Derived Class Queue from base class List
class Queue : public List
{
public:

    // Overriding the virtual functions of class List
    void store(int n)
    {

        // Queue Insert Logic

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

        // Queue Delete Logic

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
        // Printing by Linked list traversing

        Node *ptr = queue.head;
        while (ptr != NULL)
        {
            output << ptr->data << std::endl;
            ptr = ptr->next;
        }
        return output;
    }
};


// Driver Code
int main()
{
    // Making objects of Stack and Queue
    Stack S;
    Queue Q;

    // Performing operations on Stack
    std::cout << "Stack: " << std::endl;
    std::cout << S;
    S.store(10);
    S.store(20);
    std::cout << "After Storing twice Stack: " << std::endl;
    std::cout << S;
    std::cout << "Retriving once: " << S.retrive() << std::endl;
    std::cout << "Retriving twice: " << S.retrive() << std::endl;
    std::cout << "Retriving thrice: " << S.retrive() << std::endl
              << std::endl;

    // Performing operations on Queue
    std::cout << "Queue: " << std::endl;
    std::cout << Q;
    Q.store(30);
    Q.store(40);
    std::cout << "After Storing twice Queue: " << std::endl;
    std::cout << Q;
    std::cout << "Retriving once: " << Q.retrive() << std::endl;
    std::cout << "Retriving twice: " << Q.retrive() << std::endl;
    std::cout << "Retriving thrice: " << Q.retrive() << std::endl;

    return 0;
}