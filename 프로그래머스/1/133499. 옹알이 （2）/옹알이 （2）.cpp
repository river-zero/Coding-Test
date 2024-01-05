#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (string s : babbling) {
        int dup = 0;
        
        for (int i = 0; i < s.size();) {
            if (s.substr(i, 3) == "aya" && dup != 1) { dup = 1; i += 3; }
            else if (s.substr(i, 2) == "ye" && dup != 2) { dup = 2; i += 2; }
            else if (s.substr(i, 3) == "woo" && dup != 3) { dup = 3; i += 3; }
            else if (s.substr(i, 2) == "ma" && dup != 4) { dup = 4; i += 2; }
            else { dup = 0; break; }
        }
        
        if (dup) answer++;
    }
    
    return answer;
}