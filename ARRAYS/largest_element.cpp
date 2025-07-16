#include <iostream>
using namespace std;
int main() {
    int arr[] = {10,20,5,30}, maxVal=arr[0];
    for(int i=1; i<4; i++) if(arr[i]>maxVal) maxVal=arr[i];
    cout << "Largest: " << maxVal;
    return 0;
}
