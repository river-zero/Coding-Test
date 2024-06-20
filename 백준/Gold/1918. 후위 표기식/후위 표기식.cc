#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 연산자의 우선순위를 반환하는 함수
int getPriority(char op) {
    if (op == '(' || op == ')') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix;

    for (char ch : infix) {
        if ('A' <= ch && ch <= 'Z') {
            // 피연산자(알파벳)일 경우 출력
            postfix += ch;
        } else if (ch == '(') {
            // 여는 괄호일 경우 스택에 push
            s.push(ch);
        } else if (ch == ')') {
            // 닫는 괄호일 경우 여는 괄호가 나올 때까지 pop하고 출력
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // 여는 괄호 제거
        } else {
            // 연산자일 경우 우선순위가 낮은 연산자를 만날 때까지 pop하고 출력
            while (!s.empty() && getPriority(s.top()) >= getPriority(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // 스택에 남아 있는 모든 연산자를 pop하고 출력
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << postfix << "\n";

    return 0;
}
