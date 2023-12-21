#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = s;
    
    for(char& word : answer) {
        for (int i = 0; i < index; i++) {
            // 다음 문자로 이동하고 범위를 넘어서면 알파벳 순환 처리
            word++;
            if (word > 122) word -= 26;
            
            // 스킵 문자열에 현재 문자가 포함되어 있다면 다음 문자로 이동
            while (skip.find(word) != string::npos) {
                word++;
                if (word > 122) word -= 26;
            }
        }
    }
    
    return answer;
}