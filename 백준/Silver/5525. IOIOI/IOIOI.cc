#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;

    int count = 0;
    int result = 0;
    for (int i = 1; i < M - 1; i++) {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            count++;
            if (count == N) {
                count--;
                result++;
            }
            i++;
        } else {
            count = 0;
        }
    }

    cout << result << endl;

    return 0;
}