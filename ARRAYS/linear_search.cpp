#include <iostream>
using namespace std;
int main() {
    int arr[] = {5,8,1,9,4}, key = 9;
    for(int i=0; i<5; i++) {
        if(arr[i] == key) {
            cout << "Found at index " << i;
            break;
        }
    }
    return 0;
}
