#include <iostream>
using namespace std;
int main() {
    int arr[] = {1,2,3,4,5}, sorted=1;
    for(int i=0; i<4; i++) if(arr[i]>arr[i+1]) { sorted=0; break; }
    cout << (sorted ? "Sorted" : "Not Sorted");
    return 0;
}
