#include <stdio.h> // Header files
#include <stdlib.h>

// Macro to swap 2 numbers
#define swap(a, b)    \
    {                 \
        int temp = a; \
        a = b;        \
        b = temp;     \
    }

// Prototyping the functions
void selection_sort(int[], int);
void bubble_sort(int[], int);
void insertion_sort(int[], int);
void quick_sort(int[], int);
void heap_sort(int[], int);
int *merge_sort(int[], int);

// Driver Code
int main()
{
    // Original list to be sorted and its size
    int array[] = {-82, 94, -42, -2, -84, 89, -49, 45, -12, 100, -35, -45, 77, -47, 16, 31, -65, 58, 99, -63, -51, -88, -78, 25, 90, -15, 91, -43, 84, -34};
    int size = 30;

    // Names cache for printing
    char sorting_methods[5][15] = {"Selection", "Bubble", "Insertion", "Quick", "Heap"};

    // Copying the original list, since some functions perform swaps on original list
    int copies[5][30];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 30; j++)
            copies[i][j] = array[j];

    // Sorting the copies
    selection_sort(copies[0], size);
    bubble_sort(copies[1], size);
    insertion_sort(copies[2], size);
    quick_sort(copies[3], size);
    heap_sort(copies[4], size);

    // Merge sort Creates new array
    int *merge_sorted_list = merge_sort(array, size);

    // Printing the original list
    printf("Original List which was to be sorted: \n");
    for (int j = 0; j < 30; j++)
        printf("%d, ", array[j]);
    printf("\n");

    // Printing the sorted lists except merge sort
    for (int i = 0; i < 5; i++)
    {
        printf("\nSorting the list using %s sort:\n", sorting_methods[i]);
        for (int j = 0; j < 30; j++)
            printf("%d, ", copies[i][j]);
        printf("\n");
    }

    // Printing the merge sort lisst
    printf("\nSorting the list using Merge sort:\n");
    for (int j = 0; j < 30; j++)
        printf("%d, ", merge_sorted_list[j]);

    return 0;
}

//====================== SELECTION SORT======================
void selection_sort(int array[], int size)
{
    // Selects the smallest elements and brings it to the starting
    int smallest_element_index;
    for (int i = 0; i < size - 1; i++)
    {
        smallest_element_index = i;
        for (int j = i; j < size; j++)
            if (array[j] < array[smallest_element_index])
                smallest_element_index = j;

        if (i != smallest_element_index)
            swap(array[i], array[smallest_element_index]);
    }
}

//====================== BUBBLE SORT======================
void bubble_sort(int array[], int size)
{
    // This function sorts the array using bubble sort
    // Bubble sort bringss the biggest element to the end
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}

//====================== INSERTION SORT======================
void insertion_sort(int array[], int size)
{
    // Insertion sort divides the list into sorted and unsorted part
    // brings each element from unsorted part into sorted part and
    // move it to its position in the sorted list
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0; j--)
            if (array[j] < array[j - 1])
                swap(array[j], array[j - 1])
            else
                break;
}

//====================== HEAP SORT======================
void heapify(int array[], int size, int index)
{
    // Heapify converts an array to a max heap

    // Finds the largest of elements at indices i, 2i + 1, 2i + 2
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if ((left < size) && (array[left] > array[largest]))
        largest = left;

    if ((right < size) && (array[right] > array[largest]))
        largest = right;

    // if value at index wasn't the largest
    if (index != largest)
    {
        // swap value largest and index
        swap(array[index], array[largest]);

        // heapify largest index (which is not largest now)
        heapify(array, size, largest);
    }
}

void heap_sort(int array[], int size)
{
    // Heap sort converts the array into max heap and then systemetically removes the largest elements from heap
    // and create a new sorted list

    // leaf members for heap are from index size/2 and above
    // Not includig non leaf members to increase speed
    int non_leaf_members = size / 2 - 1;
    for (int i = non_leaf_members; i >= 0; i--)
        heapify(array, size, i); // convert array to max heap

    // remove max element and heapify the remaining elements
    for (int i = size - 1; i > 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

//====================== MERGE SORT======================
int *merge_sort(int array[], int size)
{
    // Merge sort works by dividing the list into 2 lists,
    // sorting the sub lists and merging them back to form the sorted final list

    // merge sort creates a new array to store the sorted list
    // Returns NULL if overflow

    // allocating space to returner array which is the new array
    int *returner_array = (int *)malloc(sizeof(int) * size);

    // Overflow
    if (returner_array == NULL)
    {
        printf("Overflow\n");
        return NULL;
    }

    // If the array size is 1, list is already sorted
    if (size == 1)
    {
        *returner_array = *array;
        return returner_array;
    }

    // dividing the list into 2 parts
    int mid_pt = size / 2;

    // sorting the two halves by recursion
    int *sorted_first_half = merge_sort(array, mid_pt);
    int *sorted_second_half = merge_sort(array + mid_pt, size - mid_pt);

    // If either of the halves are null means overflow detected
    if (sorted_first_half == NULL || sorted_second_half == NULL)
        return NULL;

    // MERGING

    int first_half_index = 0, second_half_index = 0, final_list_index = 0;
    // While loop till either halves are exhausted
    while (first_half_index < mid_pt && second_half_index < size - mid_pt)
    {
        // Going through elements of both lists and adding the elements into the returner array sequentially
        if (sorted_first_half[first_half_index] <= sorted_second_half[second_half_index])
        {
            returner_array[final_list_index] = sorted_first_half[first_half_index];
            first_half_index++;
        }
        else
        {
            returner_array[final_list_index] = sorted_second_half[second_half_index];
            second_half_index++;
        }
        final_list_index++;
    }

    // One half is exhausted, in other some elements are left

    // Add elements of first half if its not empty
    while (first_half_index < mid_pt)
    {
        returner_array[final_list_index] = sorted_first_half[first_half_index];
        first_half_index++;
        final_list_index++;
    }

    // Add elements of second half if its not empty
    while (second_half_index < size - mid_pt)
    {
        returner_array[final_list_index] = sorted_second_half[second_half_index];
        second_half_index++;
        final_list_index++;
    }

    // Free the memory allocated by the halves
    free(sorted_first_half);
    free(sorted_second_half);

    return returner_array;
}

//====================== QUICK SORT======================
int find_pivot(int array[], int low, int high)
{
    // Finding the pivot for quick sort
    // This function uses the median of 3 to find the pivot

    int pivot = (low + high) / 2;

    // code for shifting the smallest of first last and middle elements to first index,
    // largest to last index, and the median to middle index

    if (array[low] > array[high])
        swap(array[low], array[high]);

    if (array[low] > array[pivot])
        swap(array[low], array[pivot]);

    if (array[pivot] > array[high])
        swap(array[pivot], array[high]);

    // returning the median
    return pivot;
}

int partition(int array[], int low, int high)
{
    // Partition is done by taking a pointer to the left most element and one at right most element
    // swap right and left if left is higher than pivot and right is smaller than pivot
    // replace the pivot with their position when they coincide or cross

    // keeping the copies to remember the bounds of array
    int low_copy = low, high_copy = high;
    // getting the pivot
    int pivot = find_pivot(array, low, high);

    while (1)
    {
        // while low is smaller than pivot and low and high didnt cross
        while ((low <= high) && (array[low] <= array[pivot]))
            low++;

        // while high is smaller than pivot and low and high didnt cross
        while ((low <= high) && (array[high] >= array[pivot]))
            high--;

        // here either low and high crossed or high is smaller than pivot and low is greater than pivot

        // if high and low crossed
        if (low > high)
        {
            // if they met at left end
            if (high < low_copy)
                high = low;

            // if they met at right end
            if (low > high_copy)
                low = high;

            // if they met at left of pivot
            if (high < pivot)
            {
                swap(array[low], array[pivot]);
                pivot = low;
            }

            // if they met at right of pivot
            else
            {
                swap(array[high], array[pivot]);
                pivot = high;
            }
            break;
        }

        // if high is smaller than pivot and low is greater than pivot
        swap(array[high], array[low]);
    }

    // return the new position of pivot after swap
    return pivot;
}

void quick_sort_recursion(int array[], int low, int high)
{
    // This function recursively partitions the array into 2 parts and applies quick sort on both parts
    if (low < high)
    {
        int pivot = partition(array, low, high);
        // if statement for cases pivot == low or pivot == high
        if (pivot > low)
            quick_sort_recursion(array, low, pivot - 1);
        if (pivot < high)
            quick_sort_recursion(array, pivot + 1, high);
    }
}

void quick_sort(int array[], int size)
{
    // Uses the recursion function to sort the array using quicksort algorithm
    quick_sort_recursion(array, 0, size - 1);
}