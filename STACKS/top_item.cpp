#include<iostream>
#include <stack>
using namespace std;
int main() {
// This program demonstrates the use of a stack in C++

  // Create a stack of integers
stack<int>mystack;

 mystack.push(10);
 mystack.push(20);   
 mystack.push(30);
 mystack.push(40);
 mystack.push(50);
 mystack.push(60);

 cout << "Top element of stack is: " << mystack.top() << endl;

 return 0;
}