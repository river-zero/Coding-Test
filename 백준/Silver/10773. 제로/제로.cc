#include <iostream>
#include <stack>
using namespace std;

int main() {
    int K;
    cin >> K;
    
    stack<int> numbers;
    
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        
        if (num == 0) {
            if (!numbers.empty()) {
                numbers.pop();
            }
        } else {
            numbers.push(num);
        }
    }
    
    int sum = 0;
    while (!numbers.empty()) {
        sum += numbers.top();
        numbers.pop();
    }
    
    cout << sum << endl;
    
    return 0;
}