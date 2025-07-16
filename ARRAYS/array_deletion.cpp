#include <iostream>
using namespace std;
int main() {
    int arr[] = {1,2,3,4,5}, n=5, pos=3;
    for(int i=pos-1; i<n-1; i++) arr[i] = arr[i+1];
    n--;
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    return 0;
}
