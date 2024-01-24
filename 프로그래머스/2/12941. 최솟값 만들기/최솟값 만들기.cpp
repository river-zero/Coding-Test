#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    // 최솟값을 얻으려면 작은 값과 큰 값이 서로 곱함
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for(int i = 0; i < A.size(); i++) answer += A[i] * B[i];

    return answer;
}