#include <iostream>
using namespace std;

int main()
{
    int i, num, first, last, middle;
    int x, y, size, temp;
    int sz;

    // Input the size of the array
    cout << "Enter the size of array: ";
    cin >> sz;

    // Generate an array of random numbers between 1 and 5000
    int randArray[sz];
    int arr[5000];
    for (int i = 0; i < sz; i++)
        randArray[i] = 1 + rand() % 5000;

    // Display the generated array
    cout << "The generated array: ";
    for (int i = 0; i < sz; i++)
        cout << randArray[i] << " ";

    // Copy the generated array to another array for sorting
    for (int x = 0; x < sz; x++)
        arr[x] = randArray[x];

    // Sort the array in ascending order using bubble sort
    for (x = 0; x < sz; x++)
    {
        for (y = x; y < sz; y++)
        {
            if (arr[x] > arr[y + 1])
            {
                temp = arr[x];
                arr[x] = arr[y + 1];
                arr[y + 1] = temp;
            }
        }
    }

    // Display the sorted array
    cout << "\n\nElements sorted in ascending order: ";
    for (x = 0; x < sz; x++)
    {
        cout << arr[x] << " ";
    }

    // Binary search for a user-specified element
    cout << "\n\nEnter Element to be Searched: ";
    cin >> num;
    first = 0;
    last = sz - 1;
    middle = (first + last) / 2;

    while (first <= last)
    {
        if (arr[middle] < num)
            first = middle + 1;
        else if (arr[middle] == num)
        {
            cout << "\nThe number, " << num << " found at Position " << middle;
            break;
        }
        else
            last = middle - 1;

        middle = (first + last) / 2;
    }

    if (first > last)
        cout << "\nThe number, " << num << " is not found in the given Array";

    cout << endl;
    return 0;
}
