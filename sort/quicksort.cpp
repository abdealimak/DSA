#include <iostream>
using namespace std;

// Partition: places pivot in its correct sorted position
// Elements smaller than pivot go left, larger go right
// Returns the final index of the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;       // i tracks the boundary of elements <= pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;                     // Expand the "less than pivot" region
            swap(arr[i], arr[j]);    // Move smaller element to the left side
        }
    }

    // Place pivot in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return pivot's final index
}

// Quick Sort: Divide and Conquer — partition around a pivot, then recursively sort partitions
// Time Complexity: O(n log n) average, O(n^2) worst case (sorted input with last-element pivot)
// Space Complexity: O(log n) average for recursion stack
void quickSort(int arr[], int low, int high) {
    if (low >= high) return; // Base case: 0 or 1 element is already sorted

    int pi = partition(arr, low, high); // pi = pivot index after partitioning

    quickSort(arr, low, pi - 1);  // Recursively sort left of pivot
    quickSort(arr, pi + 1, high); // Recursively sort right of pivot
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "After  sorting: ";
    printArray(arr, n);

    return 0;
}