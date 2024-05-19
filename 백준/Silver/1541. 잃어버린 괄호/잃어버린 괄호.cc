#include <iostream>
#include <string>
using namespace std;

int main() {
    string expression;
    cin >> expression;
    
    int result = 0;
    string num = "";
    bool isMinus = false;
    
    for (int i = 0; i <= expression.length(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || i == expression.length()) {
            if (isMinus) {
                result -= stoi(num);
            } else {
                result += stoi(num);
            }
            num = "";
            
            if (expression[i] == '-') {
                isMinus = true;
            }
        } else {
            num += expression[i];
        }
    }
    
    cout << result << endl;
    
    return 0;
}