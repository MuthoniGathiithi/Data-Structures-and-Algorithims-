#include<iostream>
using namespace std;

class Stack {
private:
    int* arr;           // Array to store stack elements
    int top;            // Index of top element
    int capacity;       // Maximum capacity of stack

public:
    // Constructor
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Push operation - adds element to top of stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << "Pushed " << x << " to stack" << endl;
    }

    // Pop operation - removes and returns top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
            return -1;
        }
        int poppedElement = arr[top--];
        cout << "Popped " << poppedElement << " from stack" << endl;
        return poppedElement;
    }

    // Peek operation - returns top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Get current size of stack
    int size() {
        return top + 1;
    }

    // Display all elements in stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== MINI STACK PROGRAM ===" << endl;
    cout << "Creating a stack with capacity 5" << endl;
    
    Stack myStack(5);
    
    cout << "\n--- Testing Push Operations ---" << endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    
    cout << "\n--- Current Stack Status ---" << endl;
    myStack.display();
    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.peek() << endl;
    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (myStack.isFull() ? "Yes" : "No") << endl;
    
    cout << "\n--- Testing Stack Overflow ---" << endl;
    myStack.push(60); // This should cause overflow
    
    cout << "\n--- Testing Pop Operations ---" << endl;
    myStack.pop();
    myStack.pop();
    myStack.display();
    
    cout << "\n--- Testing Peek Operation ---" << endl;
    cout << "Top element after pops: " << myStack.peek() << endl;
    
    cout << "\n--- Emptying the Stack ---" << endl;
    while (!myStack.isEmpty()) {
        myStack.pop();
    }
    
    cout << "\n--- Testing Stack Underflow ---" << endl;
    myStack.pop(); // This should cause underflow
    
    cout << "\n--- Final Stack Status ---" << endl;
    myStack.display();
    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    
    cout << "\n=== PROGRAM COMPLETED ===" << endl;
    
    return 0;
}
