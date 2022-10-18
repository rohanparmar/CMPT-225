// Improved implementation of quicksort
// Quicksort can be improved using the following techniques:
// 1. Pivot selection using median of three strategy
// 2. Insertion sort for small subarrays
// 3. Use tail recursion, then replace tail recursion with a loop
// 4. First call: call quicksort recursively on the smaller subarray

#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// First improvement: use median of three strategy to select pivot
int median(int a, int b, int c)
{
    return (a + b + c) / 3;
}

int partition(int arr[], int low, int high)
{
    int index = median(low, (low + high) / 2, high);
    int pivot = arr[index];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void insertionSort(int arr[], int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int low, int high)
{
    // Second improvement: use insertion sort for small subarrays
    if (sizeof(arr) / sizeof(arr[0]) < 10)
    {
        insertionSort(arr, low, high);
    }
    else
    {
        if (low < high)
        {
            int p = partition(arr, low, high);

            quickSort(arr, low, p);
            quickSort(arr, p + 1, high);
        }
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 11, 17, 15, 19, 2, 3, 4, 6, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}