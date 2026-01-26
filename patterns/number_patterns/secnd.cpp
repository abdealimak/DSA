/*
1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 
*/

#include <iostream>
using namespace std;

int main(){
    for(int i = 0; i < 6; i++){
        for(int j = 1; j <= i; j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}