#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    // 제품과 수량을 맵에 저장
    unordered_map<string, int> m;
    for (int i = 0; i < want.size(); i++) {
        m[want[i]] = number[i];
    }
    
    // 할인기간을 모두 순회
    for (int i = 0; i < discount.size() - 9; i++) {
        bool can = true;
        unordered_map<string, int> temp = m;
        
        // 10일 동안 제품 확인
        for (int j = i; j < i + 10; j++) {
            temp[discount[j]]--;
        }
        
        // 제품이 아직 남아있다면 실패
        for (auto c : temp) {
            if (c.second) {
                can = false;
                break;
            }
        }
        
        if (can) answer++;
    }
    
    return answer;
}