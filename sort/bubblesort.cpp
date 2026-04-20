#include <iostream>
using namespace std;

// Bubble Sort: repeatedly swaps adjacent elements if they are in the wrong order
// Time Complexity: O(n^2) | Space Complexity: O(1)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Optimization: stop early if no swaps in a pass

        // Each pass "bubbles" the largest unsorted element to its correct position
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swaps occurred, array is already sorted
        if (!swapped) break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "After  sorting: ";
    printArray(arr, n);

    return 0;
}