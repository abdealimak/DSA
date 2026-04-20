#include <iostream>
using namespace std;

// Insertion Sort: builds the sorted array one element at a time
// Picks each element and inserts it into its correct position among already-sorted elements
// Time Complexity: O(n^2) | Space Complexity: O(1)
// Best case O(n) when array is already sorted
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // The element to be positioned
        int j = i - 1;

        // Shift elements of the sorted portion that are greater than key
        // one position to the right to make room for key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key in its correct position
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "After  sorting: ";
    printArray(arr, n);

    return 0;
}