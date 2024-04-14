#include <iostream>
#include <vector>

using namespace std;

bool is_promising(int i, vector<int>& position) {
    for (int j = 0; j < i; j++) {
        if (position[j] == position[i] || abs(position[i] - position[j]) == (i - j)) {
            return false;
        }
    }
    return true;
}

void solve(int i, int n, int& answer, vector<int>& position) {
    if (i == n) {
        answer++;
    } else {
        for (int j = 0; j < n; j++) {
            position[i] = j;
            
            if (is_promising(i, position)) {
                solve(i + 1, n, answer, position);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> position(n);
    int answer = 0;
    solve(0, n, answer, position);
    cout << answer << '\n';
}
