#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    
    // 우선순위를 큐에 저장
    for (const auto& e : priorities) q.emplace(e);
    
    // 우선순위 내림차순 정렬
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    while (true) {
        // 현재 문서의 우선순위가 가장 높은 경우
        if (q.front() == priorities[0]) {
            answer++;
            q.pop();
            priorities.erase(priorities.begin());
            
            // 만약 찾고자 하는 문서가 출력되었으면 리턴
            if (location == 0) return answer;
            else location--;
        } 
        
        // 현재 문서의 우선순위가 가장 높지 않은 경우
        else { 
            q.emplace(q.front()); 
            q.pop();
            location--;
            
            // 순환 가능하도록 함
            if (location < 0) location = q.size() - 1;
        }
    }
    
    return answer;
}