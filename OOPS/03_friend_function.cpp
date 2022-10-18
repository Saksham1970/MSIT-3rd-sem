#include <iostream> // Header files
#include <string>

class BankAccount
{
    // The class for Bank Account

private:
    std::string name;
    float balance;

public:
    // Constructor
    BankAccount(std::string name, float balance)
    {
        this->name = name;
        this->balance = balance;
    }

    // ostream operator overloading for printing
    friend std::ostream &operator<<(std::ostream &output, const BankAccount &acc)
    {
        output << "Name: " << acc.name << ", Balance: " << acc.balance;
        return output;
    }

    // friend function for printing greater balance
    friend void greater_balance(const BankAccount &, const BankAccount &);
};

// Friend function definiton
void greater_balance(const BankAccount &acc1, const BankAccount &acc2)
{
    std::cout << (acc1.balance > acc2.balance ? acc1.name : acc2.name) << " has more balance";
}

// Driver code
int main()
{

    // Initialising few objects
    BankAccount acc1("Saksham Gupta", 1000000);
    BankAccount acc2("Jatin Suteri", 0.02);

    // Printing them
    std::cout << acc1 << std::endl;
    std::cout << acc2 << std::endl;

    // Calling the friend function
    greater_balance(acc1, acc2);
}