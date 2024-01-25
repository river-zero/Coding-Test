#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    // 자기 자신은 무조건 포함
    int answer = 1;
    
    for (int i = 1; i < n; i++) {
        int sum = 0;
        int start = i;
        
        while (sum < n) {
            sum += start++;
        }
        
        if (sum == n) answer++;
    }
    
    return answer;
}