#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class ArrayOperations {
private:
    int* arr;
    int size;
    int capacity;

public:
    // Constructor
    ArrayOperations(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    // Destructor
    ~ArrayOperations() {
        delete[] arr;
    }

    // Insert element at end
    void insert(int element) {
        if (size < capacity) {
            arr[size] = element;
            size++;
            cout << "Inserted " << element << " successfully!" << endl;
        } else {
            cout << "Array is full! Cannot insert " << element << endl;
        }
    }

    // Insert element at specific position
    void insertAtPosition(int element, int pos) {
        if (pos < 0 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (size >= capacity) {
            cout << "Array is full!" << endl;
            return;
        }
        
        // Shift elements to right
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i-1];
        }
        arr[pos] = element;
        size++;
        cout << "Inserted " << element << " at position " << pos << endl;
    }

    // Delete element by value
    void deleteByValue(int element) {
        int pos = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                pos = i;
                break;
            }
        }
        
        if (pos == -1) {
            cout << "Element " << element << " not found!" << endl;
            return;
        }
        
        // Shift elements to left
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Deleted " << element << " successfully!" << endl;
    }

    // Delete element at position
    void deleteAtPosition(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!" << endl;
            return;
        }
        
        int element = arr[pos];
        // Shift elements to left
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Deleted element " << element << " at position " << pos << endl;
    }

    // Linear search
    int linearSearch(int element) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                return i;
            }
        }
        return -1;
    }

    // Binary search (requires sorted array)
    int binarySearch(int element) {
        int left = 0, right = size - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == element) {
                return mid;
            }
            if (arr[mid] < element) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    // Find largest element
    int findLargest() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return INT_MIN;
        }
        
        int largest = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }
        return largest;
    }

    // Find smallest element
    int findSmallest() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return INT_MAX;
        }
        
        int smallest = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] < smallest) {
                smallest = arr[i];
            }
        }
        return smallest;
    }

    // Find second largest element
    int findSecondLargest() {
        if (size < 2) {
            cout << "Array needs at least 2 elements!" << endl;
            return INT_MIN;
        }
        
        int largest = INT_MIN, secondLargest = INT_MIN;
        for (int i = 0; i < size; i++) {
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            } else if (arr[i] > secondLargest && arr[i] != largest) {
                secondLargest = arr[i];
            }
        }
        return secondLargest;
    }

    // Reverse array
    void reverse() {
        int start = 0, end = size - 1;
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
        cout << "Array reversed successfully!" << endl;
    }

    // Sort array using bubble sort
    void bubbleSort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
        cout << "Array sorted successfully!" << endl;
    }

    // Check if array is sorted
    bool isSorted() {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    // Rotate array left by one position
    void rotateLeft() {
        if (size <= 1) return;
        
        int first = arr[0];
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = first;
        cout << "Array rotated left by one position!" << endl;
    }

    // Rotate array right by one position
    void rotateRight() {
        if (size <= 1) return;
        
        int last = arr[size - 1];
        for (int i = size - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
        cout << "Array rotated right by one position!" << endl;
    }

    // Display array
    void display() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Get array size
    int getSize() {
        return size;
    }

    // Check if array is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if array is full
    bool isFull() {
        return size == capacity;
    }
};

void displayMenu() {
    cout << "\n========== ARRAY OPERATIONS MENU ==========" << endl;
    cout << "1.  Insert element at end" << endl;
    cout << "2.  Insert element at position" << endl;
    cout << "3.  Delete element by value" << endl;
    cout << "4.  Delete element at position" << endl;
    cout << "5.  Linear search" << endl;
    cout << "6.  Binary search (requires sorted array)" << endl;
    cout << "7.  Find largest element" << endl;
    cout << "8.  Find smallest element" << endl;
    cout << "9.  Find second largest element" << endl;
    cout << "10. Reverse array" << endl;
    cout << "11. Sort array (Bubble Sort)" << endl;
    cout << "12. Check if array is sorted" << endl;
    cout << "13. Rotate array left" << endl;
    cout << "14. Rotate array right" << endl;
    cout << "15. Display array" << endl;
    cout << "16. Get array size" << endl;
    cout << "17. Check if array is empty" << endl;
    cout << "18. Check if array is full" << endl;
    cout << "0.  Exit" << endl;
    cout << "===========================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int capacity;
    cout << "Enter the capacity of the array: ";
    cin >> capacity;
    
    ArrayOperations arrayOps(capacity);
    
    int choice, element, position, result;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                arrayOps.insert(element);
                break;
                
            case 2:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position: ";
                cin >> position;
                arrayOps.insertAtPosition(element, position);
                break;
                
            case 3:
                cout << "Enter element to delete: ";
                cin >> element;
                arrayOps.deleteByValue(element);
                break;
                
            case 4:
                cout << "Enter position to delete: ";
                cin >> position;
                arrayOps.deleteAtPosition(position);
                break;
                
            case 5:
                cout << "Enter element to search: ";
                cin >> element;
                result = arrayOps.linearSearch(element);
                if (result != -1) {
                    cout << "Element found at position: " << result << endl;
                } else {
                    cout << "Element not found!" << endl;
                }
                break;
                
            case 6:
                cout << "Enter element to search: ";
                cin >> element;
                if (arrayOps.isSorted()) {
                    result = arrayOps.binarySearch(element);
                    if (result != -1) {
                        cout << "Element found at position: " << result << endl;
                    } else {
                        cout << "Element not found!" << endl;
                    }
                } else {
                    cout << "Array must be sorted for binary search!" << endl;
                }
                break;
                
            case 7:
                result = arrayOps.findLargest();
                if (result != INT_MIN) {
                    cout << "Largest element: " << result << endl;
                }
                break;
                
            case 8:
                result = arrayOps.findSmallest();
                if (result != INT_MAX) {
                    cout << "Smallest element: " << result << endl;
                }
                break;
                
            case 9:
                result = arrayOps.findSecondLargest();
                if (result != INT_MIN) {
                    cout << "Second largest element: " << result << endl;
                }
                break;
                
            case 10:
                arrayOps.reverse();
                break;
                
            case 11:
                arrayOps.bubbleSort();
                break;
                
            case 12:
                if (arrayOps.isSorted()) {
                    cout << "Array is sorted!" << endl;
                } else {
                    cout << "Array is not sorted!" << endl;
                }
                break;
                
            case 13:
                arrayOps.rotateLeft();
                break;
                
            case 14:
                arrayOps.rotateRight();
                break;
                
            case 15:
                arrayOps.display();
                break;
                
            case 16:
                cout << "Array size: " << arrayOps.getSize() << endl;
                break;
                
            case 17:
                if (arrayOps.isEmpty()) {
                    cout << "Array is empty!" << endl;
                } else {
                    cout << "Array is not empty!" << endl;
                }
                break;
                
            case 18:
                if (arrayOps.isFull()) {
                    cout << "Array is full!" << endl;
                } else {
                    cout << "Array is not full!" << endl;
                }
                break;
                
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}
