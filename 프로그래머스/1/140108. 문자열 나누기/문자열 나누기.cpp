#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int index = 0;
    
    while (index < s.size()) {
        int count = 1;
        char c = s[index++];
        
        while (index < s.size() && count) {
            if (s[index] != c) {
                count--;
            } else {
                count++;
            }
            index++;
        }
        
        answer++;
    }
    
    
    return answer;
}