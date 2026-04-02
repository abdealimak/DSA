#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n, key;
    
    n=sizeof(arr)/sizeof(arr[0]);
    
    for (int i=0;i<n;i++)
        cout <<arr[i]<<"\t";
    cout<<endl;
    
    cout<<"Enter the elemnt to be search from the above list ";
    cin>>key;

    int result = linearSearch(arr, n, key);
    cout << "Searching for "<<key<<" in a given array using linear search \n";
    if(result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found ";

    return 0;
}