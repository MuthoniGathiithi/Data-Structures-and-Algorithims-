#include <iostream>
using namespace std;

int main() {
    // Simple for loop to print numbers 1 to 10
    cout << "Printing numbers from 1 to 10:" << endl;
    
    for (int i = 1; i <= 10; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // For loop to print even numbers from 2 to 20
    cout << "\nPrinting even numbers from 2 to 20:" << endl;
    
    for (int i = 2; i <= 20; i += 2) {
        cout << i << " ";
    }
    cout << endl;
    
    // For loop with user input
    int n;
    cout << "\nEnter a number to print multiplication table: ";
    cin >> n;
    
    cout << "Multiplication table for " << n << ":" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << n * i << endl;
    }
    
    return 0;
}
