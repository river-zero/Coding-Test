#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;
    
    for (char ch : str) {
        if (ch == '(' || ch == '[') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        } else if (ch == ']') {
            if (s.empty() || s.top() != '[') {
                return false;
            }
            s.pop();
        }
    }
    
    return s.empty();
}

int main() {
    string input;
    
    while (true) {
        getline(cin, input);
        
        if (input == ".") {
            break;
        }
        
        if (isBalanced(input)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}