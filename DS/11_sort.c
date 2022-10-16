#include<stdio.h>
#include<stdlib.h>

#define swap(a, b)    \
    {                 \
        int temp = a; \
        a = b;        \
        b = temp;     \
    }

void selection_sort(int[], int);
void bubble_sort(int[], int);
void insertion_sort(int[], int);
void quick_sort(int[], int);
void heap_sort(int[], int);
int* merge_sort(int[], int);


int main(){
    int array[] = {-82, 94, -42, -2, -84, 89, -49, 45, -12, 100, -35, -45, 77, -47, 16, 31, -65, 58, 99, -63, -51, -88, -78, 25, 90, -15, 91, -43, 84, -34};
    int size = 30;

    int copies[5][30];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 30; j++)        
            copies[i][j] = array[j];

    selection_sort(copies[0], size);
    bubble_sort(copies[1], size);
    insertion_sort(copies[2], size);
    quick_sort(copies[3], size);
    heap_sort(copies[4], size);

    int *merge_sorted_list = merge_sort(array, size);

    for (int j = 0; j < 30; j++)
        printf("%d, ", array[j]);
    printf("\n");

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 30; j++)
            printf("%d, ", copies[i][j]);
        printf("\n");
    }

    for (int j = 0; j < 30; j++)
        printf("%d, ", merge_sorted_list[j]);

    return 0;
}

// SELECTION SORT
void selection_sort(int array[], int size){

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


// BUBBLE SORT
void bubble_sort(int array[], int size)
{
    // This function sorts the array using bubble sort

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}


// INSERTION SORT
void insertion_sort(int array[], int size)
{
    // This function sorts the array using bubble sort
    for (int i = 1; i < size; i++)
        for (int j = i; j > 0; j--)
            if (array[j] < array[j-1])
                swap(array[j], array[j - 1]);
}


// HEAP SORT
void heapify(int array[],int size,int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // printf("%d %d ",index, array[index]);
        if ((left < size) && (array[left] > array[largest]))
            largest = left;
        
        if ((right < size) && (array[right] > array[largest]))
            largest = right;

        // printf("%d \n", array[largest]);
        if (index != largest)
        {
            swap(array[index], array[largest]);
            heapify(array, size, largest);
        }
    }

void heap_sort(int array[], int size){

    int non_leaf_members = size / 2 - 1;
    for (int i = non_leaf_members; i >= 0; i--)
    {
        heapify(array,size,i);
    }
    
    for (int i = size -1 ; i > 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}


// MERGE SORT
int* merge_sort(int array[], int size){

    int *returner_array = (int *)malloc(sizeof(int)*size);

    
    if(returner_array == NULL){
        printf("Overflow\n");
        return NULL;
    }

    if (size == 1){
        *returner_array = *array;
        return returner_array;
    }

    int mid_pt = size / 2;

    int *sorted_first_half = merge_sort(array, mid_pt);
    int* sorted_second_half = merge_sort(array+mid_pt, size-mid_pt);

    

    if (sorted_first_half == NULL || sorted_second_half == NULL)
    {
        return NULL;
    }

    int first_half_index = 0 , second_half_index = 0, final_list_index = 0;
    
    while(first_half_index < mid_pt && second_half_index < size-mid_pt){
        if(sorted_first_half[first_half_index] <= sorted_second_half[second_half_index]){
            returner_array[final_list_index] = sorted_first_half[first_half_index];
            first_half_index++;
        }
        else{
            returner_array[final_list_index] = sorted_second_half[second_half_index];
            second_half_index++;
        }
        final_list_index++;
    }

    while(first_half_index<mid_pt){
        returner_array[final_list_index] = sorted_first_half[first_half_index];
        first_half_index++;
        final_list_index++;
    }

    while(second_half_index<size-mid_pt){
        returner_array[final_list_index] = sorted_second_half[second_half_index];
        second_half_index++;
        final_list_index++;
    }

    free(sorted_first_half);
    free(sorted_second_half);

    return returner_array;
}


// QUICK SORT
int find_pivot(int array[], int low, int high){
    int pivot = (low + high) / 2;

    if (array[low] > array[high]){
        swap(array[low], array[high]);}
    if (array[low] > array[pivot]){
        swap(array[low], array[pivot]);}
    if(array[pivot] > array[high]){
        swap(array[pivot], array[high]);}
    return pivot;
}

int partition(int array[], int low, int high){

    // Pivot using median of 3
    int low_copy = low, high_copy = high;
    int pivot = find_pivot(array, low, high);
    while(1){

        while ((low <= high) && (array[low] <= array[pivot]))
            low++;
        while((low <= high)&&(array[high] >= array[pivot] ))
            high--;
        
        if (low > high){
            if (high < low_copy)
                high = low;
            
            if (low > high_copy)
                low = high;

            if (high < pivot)
            {
                swap(array[low], array[pivot]);
                pivot = low;
            }
            else{
                swap(array[high], array[pivot]);
                pivot = high;
            }
            break;
        }

        swap(array[high], array[low]);
    }
    return pivot;
}

void quick_sort_recursion(int array[], int low, int high){
    
    if (low<high){
        int pivot = partition(array, low, high);
        if (pivot > low)
            quick_sort_recursion(array, low, pivot - 1);
        if (pivot < high)
            quick_sort_recursion(array, pivot + 1, high);
    }
}

void quick_sort(int array[],int size){
    quick_sort_recursion(array, 0, size - 1);
}