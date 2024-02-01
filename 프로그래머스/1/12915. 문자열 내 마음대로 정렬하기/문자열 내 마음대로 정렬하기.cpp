#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b, int idx) {
    if (a[idx] == b[idx]) return a < b;
    return a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
    // 람다 함수가 정의된 시점에서 n의 값을 고정
    sort(strings.begin(), strings.end(), [n](const string& a, const string& b) {
        return compare(a, b, n);
    });
    return strings;
}