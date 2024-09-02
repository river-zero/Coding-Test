#include <iostream>
using namespace std;

int main() {
    int N, T, P, cnt = 0;
    int s[6];

    cin >> N;

    for (int &score : s)
        cin >> score;

    cin >> T >> P;

    for (const int &score : s)
        cnt += (score + T - 1) / T; 

    cout << cnt << '\n' << N / P << " " << N % P << '\n';

    return 0;
}
