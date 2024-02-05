#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    // 종류별 개수를 맵에 저장
    unordered_map<string, int> map;
    for (vector<string> clothe : clothes) {
        map[clothe[1]]++;
    }

    // 모든 조합 계산
    int answer = 1;
    for (const auto& e : map) {
        answer *= e.second + 1;
    }

    // 아무것도 입지 않는 경우 제외
    return answer - 1;
}
