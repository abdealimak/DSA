#include <iostream>
using namespace std;

void selectionSort(int arr[], int size) {
for (int i = 0; i < size - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < size; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j;
}
}

int temp = arr[minIndex];
arr[minIndex] = arr[i];
arr[i] = temp;
}
}
int main() {
int arr[] = {29, 10, 14, 37, 13};
selectionSort(arr, 5);
}