#include <iostream>
using namespace std;

// Merges two sorted subarrays: arr[left..mid] and arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Temporary arrays to hold the two halves
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // Merge the two temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++]; // Left element is smaller, pick it
        else
            arr[k++] = R[j++]; // Right element is smaller, pick it
    }

    // Copy remaining elements (if any)
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Merge Sort: Divide and Conquer — splits array in half recursively, then merges sorted halves
// Time Complexity: O(n log n) always | Space Complexity: O(n) for temp arrays
void mergeSort(int arr[], int left, int right) {
    if (left >= right) return; // Base case: single element is already sorted

    int mid = left + (right - left) / 2; // Avoids integer overflow vs (left+right)/2

    mergeSort(arr, left, mid);       // Sort left half
    mergeSort(arr, mid + 1, right);  // Sort right half
    merge(arr, left, mid, right);    // Merge the two sorted halves
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "After  sorting: ";
    printArray(arr, n);

    return 0;
}