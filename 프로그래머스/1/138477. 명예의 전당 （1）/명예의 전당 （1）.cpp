#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> fame;
    
    // 모든 점수 순회
    for (auto c : score) {
        // 점수 넣고 오름차순 정렬
        fame.push_back(c);
        sort(fame.begin(), fame.end());
        
        // 만약 k를 넘으면 맨 처음 값 삭제
        if (fame.size() > k) {
            fame.erase(fame.begin());
        }
        
        // 최솟값 푸쉬
        answer.push_back(*fame.begin());
    }
    
    return answer;
}