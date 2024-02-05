#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    // 내림차순 정렬
    sort(citations.rbegin(), citations.rend());
    
    for(int i = citations.size() - 1; i >= 0; i--) {
        if(citations[i] >= i + 1) return i + 1;
    }
}