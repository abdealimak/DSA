#include <iostream>
using namespace std;

// Selection Sort: finds the minimum element from the unsorted portion
// and places it at the beginning of the unsorted portion
// Time Complexity: O(n^2) always | Space Complexity: O(1)
// Makes the minimum number of swaps: exactly O(n) swaps
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i; // Assume the first unsorted element is the minimum

        // Find the actual minimum in the remaining unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j; // Update index if a smaller element is found
        }

        // Swap the found minimum with the first unsorted element
        // (only swap if needed — avoids unnecessary operations)
        if (minIdx != i)
            swap(arr[minIdx], arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "After  sorting: ";
    printArray(arr, n);

    return 0;
}