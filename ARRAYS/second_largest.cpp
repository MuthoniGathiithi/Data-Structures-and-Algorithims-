#include <iostream>
using namespace std;
int main() {
    int arr[] = {10,20,30,25}, largest=-1, second=-1;
    for(int i=0; i<4; i++) {
        if(arr[i]>largest) {
            second=largest;
            largest=arr[i];
        } else if(arr[i]>second && arr[i]!=largest) second=arr[i];
    }
    cout << "Second Largest: " << second;
    return 0;
}
