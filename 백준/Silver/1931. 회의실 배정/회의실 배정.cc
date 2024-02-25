#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 종료 시간을 first에 저장
    vector<pair<int, int>> meetings(N);
    for (int i = 0; i < N; i++) {
        cin >> meetings[i].second >> meetings[i].first;
    }

    sort(meetings.begin(), meetings.end());

    int count = 0;
    int end_time = 0;

    for (int i = 0; i < N; i++) {
        if (meetings[i].second >= end_time) {
            end_time = meetings[i].first;
            count++;
        }
    }

    cout << count << endl;
}
