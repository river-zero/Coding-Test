#include <vector>
#include <algorithm>

using std::vector;

vector<int> solution(const vector<int> answers) {
    vector<int> answer;
    
    const int n1[] = {1, 2, 3, 4, 5};
    const int n2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    const int n3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int sum[] = {0, 0, 0};
    
    for (int i = 0; i < answers.size(); i++) {
        int ans = answers[i];
        if (ans == n1[i % 5]) sum[0]++;
        if (ans == n2[i % 8]) sum[1]++;
        if (ans == n3[i % 10]) sum[2]++;
    }
    
    const int max_count = *std::max_element(sum, sum + 3);
    
    for (int i = 0; i < 3; i++) {
        if (sum[i] == max_count) answer.push_back(i + 1);
    }
    
    return answer;
}
