#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

unordered_map<char, char> m = {{'{', '}'}, {'[', ']'}, {'(', ')'}};

int isCorrect(string s) {
    stack<char> st;
    
    for (int i = 0; i < s.size(); i++) {
        // {, [, (
        if (m[s[i]]) st.push(s[i]);
        // 스택이 들어있고 짝이 맞는 경우
        else if (!st.empty() && m[st.top()] == s[i]) st.pop();
        else st.push(s[i]);
    }
    
    // 스택이 모두 비었다면 성공
    if (!st.empty()) return 0;
    return 1;
}

int solution(string s) {
    int answer = 0;
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
        // 왼쪽으로 i만큼 회전한 문자열
        string temp = s.substr(i, n - i) + s.substr(0, i);
        answer += isCorrect(temp);
    }
    
    return answer;
}
