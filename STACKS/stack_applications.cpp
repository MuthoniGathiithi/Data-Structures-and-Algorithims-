#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Function to check if brackets are balanced
bool isBalanced(string expression) {
    stack<char> s;
    
    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        
        // Push opening brackets onto stack
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        // Check closing brackets
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) {
                return false; // No matching opening bracket
            }
            
            char top = s.top();
            s.pop();
            
            // Check if brackets match
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return s.empty(); // Stack should be empty for balanced expression
}

// Function to reverse a string using stack
string reverseString(string str) {
    stack<char> s;
    string reversed = "";
    
    // Push all characters onto stack
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }
    
    // Pop all characters to get reversed string
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    
    return reversed;
}

// Function to convert decimal to binary using stack
string decimalToBinary(int decimal) {
    if (decimal == 0) return "0";
    
    stack<int> s;
    string binary = "";
    
    // Push remainders onto stack
    while (decimal > 0) {
        s.push(decimal % 2);
        decimal = decimal / 2;
    }
    
    // Pop to get binary representation
    while (!s.empty()) {
        binary += to_string(s.top());
        s.pop();
    }
    
    return binary;
}

// Function to demonstrate stack operations
void demonstrateStackOperations() {
    stack<int> myStack;
    
    cout << "\n=== Stack Operations Demo ===" << endl;
    
    // Push elements
    cout << "Pushing elements: 10, 20, 30, 40, 50" << endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    
    cout << "Stack size: " << myStack.size() << endl;
    cout << "Top element: " << myStack.top() << endl;
    
    // Pop elements
    cout << "\nPopping elements:" << endl;
    while (!myStack.empty()) {
        cout << "Popped: " << myStack.top() << endl;
        myStack.pop();
    }
    
    cout << "Stack is now empty: " << (myStack.empty() ? "Yes" : "No") << endl;
}

int main() {
    cout << "=== STACK APPLICATIONS IN C++ ===" << endl;
    
    // 1. Bracket Matching
    cout << "\n1. BRACKET MATCHING:" << endl;
    string expressions[] = {
        "((()))",
        "([{}])",
        "((())",
        "([)]",
        "{[()()]}"
    };
    
    for (int i = 0; i < 5; i++) {
        cout << "Expression: " << expressions[i] 
             << " -> " << (isBalanced(expressions[i]) ? "Balanced" : "Not Balanced") << endl;
    }
    
    // 2. String Reversal
    cout << "\n2. STRING REVERSAL USING STACK:" << endl;
    string originalString = "Hello World";
    string reversedString = reverseString(originalString);
    cout << "Original: " << originalString << endl;
    cout << "Reversed: " << reversedString << endl;
    
    // 3. Decimal to Binary Conversion
    cout << "\n3. DECIMAL TO BINARY CONVERSION:" << endl;
    int numbers[] = {10, 25, 42, 100, 255};
    for (int i = 0; i < 5; i++) {
        cout << "Decimal " << numbers[i] << " = Binary " << decimalToBinary(numbers[i]) << endl;
    }
    
    // 4. Basic Stack Operations
    demonstrateStackOperations();
    
    // 5. Interactive Section
    cout << "\n=== INTERACTIVE SECTION ===" << endl;
    char choice;
    cout << "Do you want to test bracket matching with your own expression? (y/n): ";
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        string userExpression;
        cout << "Enter an expression with brackets: ";
        cin >> userExpression;
        cout << "Your expression: " << userExpression 
             << " -> " << (isBalanced(userExpression) ? "Balanced" : "Not Balanced") << endl;
    }
    
    cout << "\nDo you want to convert a decimal number to binary? (y/n): ";
    cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        int userNumber;
        cout << "Enter a decimal number: ";
        cin >> userNumber;
        cout << "Decimal " << userNumber << " = Binary " << decimalToBinary(userNumber) << endl;
    }
    
    cout << "\nProgram completed successfully!" << endl;
    return 0;
}
