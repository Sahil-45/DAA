#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    // Size of the temporary arrays
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // Creating temporary arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // Copying values into the temporary arrays
    int mainArrayIndex = start;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // Merging two sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergesort(int arr[], int start, int end)
{
    // Base case
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    // Recalling the function for the left part of the array
    mergesort(arr, start, mid);

    // Recalling the function for the right part of the array
    mergesort(arr, mid + 1, end);

    // Calling the merge function
    merge(arr, start, end);
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

    mergesort(arr, 0, size - 1);

    cout << "Sorted array is" << endl;
    print(arr, size);

    time(&end);
    double time_taken = double(end - start);

    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5) << " sec " << endl;

    return 0;
}
