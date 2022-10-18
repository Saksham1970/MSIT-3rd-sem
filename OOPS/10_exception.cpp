#include <iostream> // Header Files

// Sample list against which out of bound exception to be raised
int sample_list[10] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};
int sample_list_length = 10;

// Driver Code
int main()
{
    int i;
    while (true)
    {
        std::cout << "Enter the index of which element to be accessed: ";
        std::cin >> i;

        // if entered index out of bounds
        if (i < 0 or i >= sample_list_length)
            throw std::out_of_range("Index out of range."); // raise an exception
        else
            std::cout << "The element at the index is: " << sample_list[i] << std::endl;
    }
}