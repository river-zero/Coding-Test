#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    // 우선순위 큐 선언
    // 기본적으로 최대 힙
    priority_queue<int> pq(works.begin(), works.end());
    
    while (n > 0) {
        // 가장 작업량이 많은 작업을 선택하여 1 감소시킴
        int max_work = pq.top();
        pq.pop();
        
        if (max_work > 0) {
            max_work--;
            n--;
            pq.push(max_work);
        } else {
            break;
        }
    }
    
    // 남은 작업량의 제곱을 더함
    while (!pq.empty()) {
        int work = pq.top();
        pq.pop();
        answer += (long long)work * work;
    }
    
    return answer;
}
