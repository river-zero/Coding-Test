#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    if (score.size() < m) return 0;
    
    sort(score.begin(), score.end(), [](int a, int b){return a > b;});
    int num = score.size() / m;
    for (int i = 0; i < num; i++) {
        answer += score[i * m + m - 1] * m;
    }
    
    return answer;
}