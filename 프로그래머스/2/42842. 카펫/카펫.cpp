#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    // 높이는 3부터 시작
    for (int height = 3; ; height++) {
        // 총합이 높이로 나눠지는 경우
        if ((sum % height) == 0) {
            int weight = sum / height;

            // 노란색 카펫 개수가 일치하면 성공
            if ((height - 2) * (weight - 2) == yellow) {
                answer.push_back(weight);
                answer.push_back(height);
                break;
            }
        }
    }

    return answer;
}