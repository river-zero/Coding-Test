#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> m;
    
    for (int i = 0; i < keymap.size(); i++) {
        for (int j = 0; j < keymap[i].size(); j++) {
            // 맵에 이미 값이 존재하는 경우
            if (m.find(keymap[i][j]) != m.end()) {
                // 값을 비교해 최소값으로 바꿔치기
                if (m[keymap[i][j]] < j + 1) {
                    continue;
                } else {
                    m[keymap[i][j]] = j + 1;
                }
            } else {
                m[keymap[i][j]] = j + 1;
            }
        }
    }
    
    for (int i = 0; i < targets.size(); i++) {
        int count = 0;
        
        for (int j = 0; j < targets[i].size(); j++) {
            if (m.find(targets[i][j]) != m.end()) {
                count += m[targets[i][j]];
            } else {
                count = -1;
                break;
            }
        }
        
        answer.push_back(count);
    }
    
    return answer;
}