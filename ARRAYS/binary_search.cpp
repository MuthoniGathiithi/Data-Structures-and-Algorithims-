#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main() {
    int arr[] = {1,3,5,7,9}, key=7;
    int result = binarySearch(arr,5,key);
    if(result!=-1) cout << "Found at index " << result;
    else cout << "Not found";
    return 0;
}
