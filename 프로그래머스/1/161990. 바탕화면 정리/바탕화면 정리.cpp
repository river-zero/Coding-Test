#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer = {51, 51, -1, -1};
    
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[0].size(); j++) {
            if(wallpaper[i][j] == '#') {
                // 드래그의 시작점은 모든 #에서 인덱스 값이 가장 낮은 수
                // 드래그의 끝은 모든 #에서 인덱스 값이 가장 높은 수 더하기 1
                answer[0] = min(answer[0], i);
                answer[1] = min(answer[1], j);
                answer[2] = max(answer[2], i + 1);
                answer[3] = max(answer[3], j + 1);
            }
        }
    }
    
    return answer;
}