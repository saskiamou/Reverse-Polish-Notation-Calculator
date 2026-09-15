#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <stack>

#include "RPNCalculator.h"

using namespace std;

queue<string> q;
stack<int> s;

string userInput;

int main() {
    
    
    std::cout << "Enter numbers to calculate in Reverse Polish Notation: ";
    getline(cin, userInput);
    std::istringstream iss(userInput);

    string c;
    while(iss >> c) {
        q.push(c);
    }

    // While queue still has values stored, store and pop temp c value, check if it's an operation. If yes, store top of stack operands into variables a/b, otherwise push temp c into stack.
    while (!q.empty()) {
        string c = q.front();
        q.pop();
        if (isOp(c)) {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(doOp(c, a, b));
        } else {
            s.push(stoi(c));
        }

    }

    // Display final output
    std::cout << s.top() << endl;
}
// Checks if current slot is operator, if so, green flag pop 2 on stack.
bool isOp(const string& c)
{
    return c.size() == 1 &&
           (c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/');
}
// Handles operation on a and b operands
int doOp(const string& c, int a, int b) {
    switch (c[0])
    {
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*': 
        return (a * b);
    case '/':
        if (b == 0) { 
            cout << "Error, divide by zero\n";
            exit(1);
        } else return (a / b);
    default: 
        cout << "Operation not found. ";
        exit(1);
    }
        
}


