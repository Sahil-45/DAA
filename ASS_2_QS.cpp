#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// This function takes the last element as pivot, places the pivot element at its correct position in the sorted array,
// and places all smaller elements to the left of the pivot and all greater elements to the right of the pivot.
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of the smaller element, indicates the right position of the pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // Increment the index of the smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is the partitioning index, arr[p] is now at the right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    time_t start, end;
    time(&start);

    ios_base::sync_with_stdio(false);

    // Taking size as input
    cout << "Size of array" << endl;
    int size;
    cin >> size;

    int arr[size];

    cout << "Elements of array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Given array is" << endl;
    print(arr, size);

    quickSort(arr, 0, size - 1);

    cout << "Sorted array is" << endl;
    print(arr, size);

    time(&end);
    double time_taken = double(end - start);

    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5) << " sec " << endl;

    return 0;
}
