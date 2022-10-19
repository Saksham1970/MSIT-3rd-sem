// Header files
#include <stdio.h>
#include <stdlib.h>

// Prototyping the functions
void bubble_sort(int *, int, int **);
int linear_search(int[], int, int);
int binary_search(int[], int, int);
int *input_list(int *);

int main()
{
    // Getting the list inputted
    int size, *list;
    list = input_list(&size);

    // Getting the element to be searched from the user
    int search_element;
    printf("Input the search element: ");
    scanf("%d", &search_element);

    // Doing searches using functions
    int linear_index = linear_search(list, size, search_element);
    int binary_index = binary_search(list, size, search_element);

    if (linear_index >= 0)
        printf("Found the element using linear search at index %d.\n", linear_index);
    else
        printf("Could not find the element using linear search.\n", linear_index);

    if (binary_index >= 0)
        printf("Found the element using binary search at index %d. \n", binary_index);
    else
        printf("Could not find the element using binary search. \n", binary_index);

    return 0;
}

int linear_search(int list[], int size, int search_element)
{
    // This function uses linear search to find the element in list

    for (int i = 0; i < size; i++) // Traversing through the list
    {
        if (list[i] == search_element) // If element found
            return i;
    }

    // If foor loop is Completed and element not found
    return -1;
}

int binary_search(int list[], int size, int search_element)
{
    // This function searches for an element using binary search
    int *index_list;
    bubble_sort(list, size, &index_list); // binary search uses a sorted list

    int lo = 0, hi = size - 1; // first and last index
    int mid;

    // while indexes not coinciding or consecutive
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (list[mid] < search_element)
        { // element is in the second half of the list
            lo = mid + 1;
        }
        else
        { // element is in the first half of the list
            hi = mid;
        }
    }
    int lo_actual_index = index_list[lo];
    int hi_actual_index = index_list[hi];

    free(index_list);

    // Loop finished with finding the element
    if (list[lo] == search_element)
        return lo_actual_index;

    if (list[hi] == search_element)
        return hi_actual_index;

    // Loop finished without finding the element
    else
        return -1;
}

void bubble_sort(int list[], int size, int **index_list)
{
    // This function sorts the list using bubble sort
    int *local_index_list = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        local_index_list[i] = i;
    }

    *index_list = local_index_list;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (list[j] > list[j + 1])
            {
                int swap_var = list[j];
                list[j] = list[j + 1];
                list[j + 1] = swap_var;

                swap_var = local_index_list[j];
                local_index_list[j] = local_index_list[j + 1];
                local_index_list[j + 1] = swap_var;
            }
        }
    }
}

int *input_list(int *size)
{
    // This function inputs the list from user
    int *array;
    printf("Input the number of elements in the list: ");
    scanf("%d", size);

    // Allocating the memory to the array
    array = (int *)malloc(*size * sizeof(int));

    // Putting the elements into the array
    for (int i = 0; i < *size; i++)
    {
        printf("Input element no %d of the list: ", i + 1);
        scanf("%d", array + i);
    }
    return array;
}
