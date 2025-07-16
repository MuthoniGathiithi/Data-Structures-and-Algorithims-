#include <iostream>
using namespace std;
int main() {
    int arr[6] = {1,2,3,5,6};
    int n = 5, pos = 3, value = 4;
    for(int i=n; i>=pos; i--) arr[i] = arr[i-1];
    arr[pos-1] = value;
    for(int i=0; i<=n; i++) cout << arr[i] << " ";
    return 0;
}
