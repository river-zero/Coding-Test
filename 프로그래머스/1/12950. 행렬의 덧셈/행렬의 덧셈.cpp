#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    // 초기화하지 않고 사용하면 오류 발생
    vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size()));

    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr1[i].size(); j++) {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    return answer;
}