#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    map<int, int> m;
    
    for (int n : numbers) {
        m[n]++;
    }
    
    for (int i = 0; i < 10; i++) {
        if (m.find(i) == m.end()) {
            answer += i;
        }
    }
    
    return answer;
}