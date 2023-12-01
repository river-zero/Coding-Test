#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[i].size(); j++) {
            if (park[i][j] == 'S') {
                answer = {i, j};
                break;
            }
        }
    }

    for (int i = 0; i < routes.size(); i++) {
        char direction = routes[i][0];
        int distance = routes[i][2] - '0';

        vector<int> old = answer;

        // 가는 길에서 장애물을 만날 수도
        // 있으므로 한 칸씩 이동하며 확인
        for (int j = 0; j < distance; j++) {
            if (direction == 'N') {
                answer[0]--;
            } else if (direction == 'S') {
                answer[0]++;
            } else if (direction == 'W') {
                answer[1]--;
            } else if (direction == 'E') {
                answer[1]++;
            }

            if (answer[0] < 0 || answer[0] >= park.size() || answer[1] < 0 || answer[1] >= park[0].size() || park[answer[0]][answer[1]] == 'X') {
                answer = old;
                break;
            }
        }
    }

    return answer;
}