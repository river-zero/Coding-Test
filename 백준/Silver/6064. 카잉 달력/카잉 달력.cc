#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int solve(int M, int N, int x, int y) {
    int lcmValue = lcm(M, N);
    int result = -1;

    for (int i = x; i <= lcmValue; i += M) {
        if ((i - y) % N == 0) {
            result = i;
            break;
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int result = solve(M, N, x, y);
        cout << result << endl;
    }

    return 0;
}