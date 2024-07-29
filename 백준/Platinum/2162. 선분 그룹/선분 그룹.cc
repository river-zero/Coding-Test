#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

struct Line {
    Point p1, p2;
};

int parent[3001];
int groupSize[3001];

int findParent(int a) {
    if (a != parent[a]) {
        parent[a] = findParent(parent[a]);
    }
    return parent[a];
}

void unionSets(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a != b) {
        if (groupSize[a] < groupSize[b]) {
            swap(a, b);
        }
        parent[b] = a;
        groupSize[a] += groupSize[b];
    }
}

int ccw(Point a, Point b, Point c) {
    long long val = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
    if (val < 0) return -1;
    if (val > 0) return 1;
    return 0;
}

bool isIntersect(Line l1, Line l2) {
    Point p1 = l1.p1, p2 = l1.p2, p3 = l2.p1, p4 = l2.p2;
    int d1 = ccw(p1, p2, p3);
    int d2 = ccw(p1, p2, p4);
    int d3 = ccw(p3, p4, p1);
    int d4 = ccw(p3, p4, p2);
    if (d1 * d2 < 0 && d3 * d4 < 0) return true;
    if (d1 == 0 && min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x) && min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y)) return true;
    if (d2 == 0 && min(p1.x, p2.x) <= p4.x && p4.x <= max(p1.x, p2.x) && min(p1.y, p2.y) <= p4.y && p4.y <= max(p1.y, p2.y)) return true;
    if (d3 == 0 && min(p3.x, p4.x) <= p1.x && p1.x <= max(p3.x, p4.x) && min(p3.y, p4.y) <= p1.y && p1.y <= max(p3.y, p4.y)) return true;
    if (d4 == 0 && min(p3.x, p4.x) <= p2.x && p2.x <= max(p3.x, p4.x) && min(p3.y, p4.y) <= p2.y && p2.y <= max(p3.y, p4.y)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Line> lines(N);
    for (int i = 0; i < N; ++i) {
        cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
        parent[i] = i;
        groupSize[i] = 1;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (isIntersect(lines[i], lines[j])) {
                unionSets(i, j);
            }
        }
    }

    int groupCount = 0;
    int maxGroupSize = 0;
    for (int i = 0; i < N; ++i) {
        if (findParent(i) == i) {
            groupCount++;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        maxGroupSize = max(maxGroupSize, groupSize[findParent(i)]);
    }

    cout << groupCount << '\n';
    cout << maxGroupSize << '\n';

    return 0;
}
