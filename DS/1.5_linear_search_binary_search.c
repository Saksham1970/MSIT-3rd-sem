// Header files
#include <stdio.h>

int list[10] = {1, 4, 5, 10, 30, 15, 2, -1, -15, 20}; // Array which is used for searching
int size = 10; // Array's size

// Prototyping the functions
int* bubble_sort(int*,int);
void linear_search(int[],int,int);
void binary_search(int[],int,int);

int main()
{
    // Getting the element to be searched from the user
    int search_element; 
    printf("Input the search element: ");
    scanf("%d",&search_element);

    // Doing searches using functions
    linear_search(list,size,search_element);
    binary_search(list,size,search_element);

    return 0;
}

void linear_search(int list[], int size, int search_element)
{   
    //This function uses linear search to find the element in list

    for (int i = 0; i < size; i++) //Traversing through the list
    {
        if (list[i] == search_element) //If element found
        {

            printf("Found the element %d at position %d using linear search.\n", search_element, i);
            return;
        }
    }

    // If foor loop is Completed and element not found
    printf("Could not find the element %d in the list using linear search.\n", search_element);
    return;
}

void binary_search(int list[], int size, int search_element)
{
    // This function searches for an element using binary search

    int* sorted_list = bubble_sort(list,size); // binary search uses a sorted list
    
    int lo = 0, hi= size-1; // first and last index
    int mid;
    
    // while indexes not coinciding or consecutive
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2; 
        if (list[mid] < search_element) { //element is in the second half of the list
            lo = mid + 1;
        }
        else {                             //element is in the first half of the list
            hi = mid;
        }
    }

    // Loop finished with finding the element
    if (list[lo] == search_element || list[hi] == search_element) 
        printf("Found the element %d in the list using binary search.", search_element);    

    // Loop finished without finding the element
    else
        printf("Could not find the element %d in the list using binary search.\n", search_element);
    
}

int *bubble_sort(int list[], int size)
{
    //This function sorts the list using bubble sort

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (list[j] > list[j+1]) 
            {
                int swap_var = list[j];
                list[j] = list[j + 1];
                list[j + 1] = swap_var;
            }
        }
    }
    return list;
}