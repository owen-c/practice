#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const int NUM_TO_SORT = 50;

void fill_array(int* array, int array_size);
void print_array(int* array, int array_size);
void quicksort(int* array, int left, int right);
int partition(int* array, int left, int right, int pivot);

int main()
{
    int* array_to_sort = new int[NUM_TO_SORT];
    fill_array(array_to_sort, NUM_TO_SORT);

    printf("\nArray before sort:\n");
    print_array(array_to_sort, NUM_TO_SORT);

    quicksort(array_to_sort, 0, NUM_TO_SORT-1);

    printf("\nArray after sort:\n");
    print_array(array_to_sort, NUM_TO_SORT);

    delete [] array_to_sort;
    array_to_sort = NULL;
    return 0;
}

void fill_array(int* array, int array_size)
{
    srand(time(NULL));

    for (int i = 0; i < array_size; ++i)
        array[i] = rand() % array_size;
}

void print_array(int* array, int array_size)
{
    for (int i = 0; i < array_size; ++i)
    {
        if (!(i % 8) && i != 0)
            printf("\n");

        printf("%d", array[i]);
        printf("\t");
    }
    printf("\n");
}

void quicksort(int* array, int left, int right)
{
    if (left < right)
    {
        //Pick the pivot, picking the left most causes worst-case behavior for already sorted arrays
        int pivot = left;

        int new_pivot = partition(array, left, right, pivot);

        //Recursively sort elements smaller than pivot
        quicksort(array, left, new_pivot - 1);

        //Recursively sort elements greater than pivot
        quicksort(array, new_pivot + 1, right);
    }
}

int partition(int* array, int left, int right, int pivot)
{
    int swap;
    int pivot_val = array[pivot];

    //Move pivot to end
    swap = array[pivot];
    array[pivot] = array[right];
    array[right] = swap;
     
    //Partition array, less than pivot goes left, greater than goes right (of pivot)
    int store_index = left;
    for (int i = left; i < right; ++i)
    {
        if (array[i] <= pivot_val)
        {
            swap = array[i];
            array[i] = array[store_index];
            array[store_index] = swap;

            ++store_index;
        }
    }

    //Move pivot from end back to its proper place
    swap = array[store_index];
    array[store_index] = array[right];
    array[right] = swap;

    return store_index;
}
