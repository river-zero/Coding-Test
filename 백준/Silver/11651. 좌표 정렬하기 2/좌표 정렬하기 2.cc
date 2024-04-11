#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool compare(Point a, Point b) {
    if (a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}

int main() {
    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; i++) cin >> points[i].x >> points[i].y;
    sort(points.begin(), points.end(), compare);
    for (int i = 0; i < N; i++) cout << points[i].x << ' ' << points[i].y << '\n';
}
