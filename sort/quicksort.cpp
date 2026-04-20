#include <iostream>
#include <iomanip>
using namespace std;

int step = 1; // Global step counter

// Utility: Print the array with a highlighted range
void printArray(int arr[], int n, int low, int high, int pivotIdx = -1, int swapI = -1, int swapJ = -1) {
    cout << "  [ ";
    for (int k = 0; k < n; k++) {
        if (k == pivotIdx)
            cout << "\033[1;33m" << arr[k] << "(P)" << "\033[0m "; // Yellow = Pivot
        else if (k == swapI || k == swapJ)
            cout << "\033[1;32m" << arr[k] << "\033[0m ";           // Green = Swapped
        else if (k >= low && k <= high)
            cout << "\033[1;36m" << arr[k] << "\033[0m ";           // Cyan = Active range
        else
            cout << "\033[90m" << arr[k] << "\033[0m ";             // Gray = Outside range
    }
    cout << "]" << endl;
}

int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = low - 1;

    cout << "\n\033[1;35m--- Step " << step++ << ": Partition (low=" << low << ", high=" << high << ") ---\033[0m" << endl;
    cout << "  Pivot = arr[" << high << "] = \033[1;33m" << pivot << "\033[0m" << endl;
    printArray(arr, n, low, high, high);

    for (int j = low; j < high; j++) {
        cout << "  Comparing arr[" << j << "]=" << arr[j] << " with pivot=" << pivot;
        if (arr[j] <= pivot) {
            i++;
            cout << "  => " << arr[j] << " <= " << pivot << ", SWAP arr[" << i << "] and arr[" << j << "]" << endl;
            swap(arr[i], arr[j]);
            printArray(arr, n, low, high, high, i, j);
        } else {
            cout << "  => " << arr[j] << " > " << pivot << ", no swap" << endl;
        }
    }

    // Place pivot in correct position
    cout << "  Placing pivot at index " << i+1 << endl;
    swap(arr[i+1], arr[high]);
    printArray(arr, n, low, high, i+1);

    cout << "  Pivot \033[1;33m" << pivot << "\033[0m is now at FINAL position [" << i+1 << "]" << endl;
    return i + 1;
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, n);

        cout << "\n\033[1;34m  >> Recursing LEFT  (low=" << low  << ", high=" << pi-1 << ")\033[0m" << endl;
        quickSort(arr, low, pi - 1, n);

        cout << "\n\033[1;34m  >> Recursing RIGHT (low=" << pi+1 << ", high=" << high << ")\033[0m" << endl;
        quickSort(arr, pi + 1, high, n);
    } else {
        if (low == high)
            cout << "\n  \033[90mBase case: single element arr[" << low << "]=" << arr[low] << " already sorted.\033[0m" << endl;
    }
}

int main() {
    int arr[] = {9, 3, 7, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "\033[1;37m========================================\033[0m" << endl;
    cout << "\033[1;37m     QUICKSORT - Step by Step Demo      \033[0m" << endl;
    cout << "\033[1;37m========================================\033[0m" << endl;
    cout << "\nLegend: \033[1;33mYellow=Pivot\033[0m  \033[1;36mCyan=Active Range\033[0m  \033[1;32mGreen=Swapped\033[0m  \033[90mGray=Outside\033[0m\n";

    cout << "\nOriginal Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1, n);

    cout << "\n\033[1;32m========================================\033[0m" << endl;
    cout << "\033[1;32m         FINAL SORTED ARRAY             \033[0m" << endl;
    cout << "\033[1;32m========================================\033[0m" << endl;
    cout << "  [ ";
    for (int i = 0; i < n; i++) cout << "\033[1;32m" << arr[i] << "\033[0m ";
    cout << "]\n" << endl;

    return 0;
}