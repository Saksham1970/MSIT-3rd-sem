#include <iostream> // Header Files
using namespace std;

int sample_list[10] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23};
int sample_list_length = 10;

// Driver Code
int main()
{
    int i;
    while (true)
    {
        cout << "Enter the index of which element to be accessed: ";
        cin >> i;
        if (i < 0 or i >= sample_list_length)
        {
            throw out_of_range("Index out of range.");
        }
        else
        {
            cout << "The element at the index is: " << sample_list[i] << endl;
        }
    }
}