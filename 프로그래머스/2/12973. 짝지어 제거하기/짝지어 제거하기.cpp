#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    stack<char> stk;

    for (char c : s) {
        if (!stk.empty() && stk.top() == c) {
            stk.pop();
        } else {
            stk.push(c);
        }
    }

    return stk.empty() ? 1 : 0;
}