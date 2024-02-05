#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;

    // 귤 크기별로 몇 개인지 맵에 저장
    for (int e : tangerine) {
        m[e]++;
    }

    // 크기를 내림차순으로 정렬
    std::vector<std::pair<int, int>> v(m.begin(), m.end());
    std::sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // 크기가 가장 많은 순서대로 k개씩 묶어 크기 종류를 최소화
    for (const auto& p : v) {
        int count = min(p.second, k);
        k -= count;
        answer++;
        
        if (k == 0) {
            break;
        }
    }

    return answer;
}