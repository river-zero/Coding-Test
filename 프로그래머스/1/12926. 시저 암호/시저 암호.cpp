#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer.push_back(' ');
        } else {
            // 알파벳 범위에 주의
            char base = islower(s[i]) ? 'a' : 'A';
            s[i] = (s[i] - base + n) % 26 + base;
            answer.push_back(s[i]);
        }
    }
    
    return answer;
}