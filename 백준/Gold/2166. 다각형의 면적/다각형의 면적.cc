#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    long long x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    long long area = 0;
    for (int i = 0; i < N; ++i) {
        int j = (i + 1) % N;
        area += points[i].x * points[j].y;
        area -= points[i].y * points[j].x;
    }

    area = abs(area);
    cout << fixed;
    cout.precision(1);
    cout << area / 2.0 << '\n';

    return 0;
}
