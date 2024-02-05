#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    int n = elements.size();

    for (int i = 0; i < n; i++) {
        int sum = 0;
        
        for (int j = 0; j < n; j++) {
            sum += elements[(i + j) % n];
            // 원형 수열의 특성을 고려하여 인덱스 계산
            s.insert(sum);
        }
    }

    return s.size();
}
