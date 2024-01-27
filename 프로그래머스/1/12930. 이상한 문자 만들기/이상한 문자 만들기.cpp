#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            index = 0;
            answer += ' ';
            continue;
        }
        
        if (index % 2 == 0) {
            answer += toupper(s[i]);
            index++;
        } else {
            answer += tolower(s[i]);
            index++;
        }
    }
    
    return answer;
}