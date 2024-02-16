#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> scores;
    double sum = 0;
    
    // 개수 입력받고 벡터에 점수 푸쉬
    cin >> n;
    for (int i = 0; i < n; i++) {
        int score;
        cin >> score;
        scores.push_back(score);
    }
    
    // sort는 기본적으로 오름차순
    // greater<int>()을 더 넘겨주면 내림차순
    sort(scores.begin(), scores.end());
    int max_score = scores[scores.size() - 1];
    
    for (int i = 0; i < n; i++) {
        sum += scores[i] / static_cast<double>(max_score) * 100;
    }
    
    cout << sum / n;
}