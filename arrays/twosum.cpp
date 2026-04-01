#include <iostream>
using namespace std;

bool findPair (int a[], int n, int z)
{
for (int i = 0; i < n; i++)
{

for (int j= i + 1 ; j < n; j++)
{

if (a[i] + a[j] == z)
return true;
}
}
return false;
}

int main()
{
    int a[] = {1,-2,1,0,5};
    int z = -1;
    int n = sizeof(a) / sizeof(a[0]);

    if (findPair(a,n,z))
    cout <<"True";
    else
    cout <<"False";

    return 0;

}