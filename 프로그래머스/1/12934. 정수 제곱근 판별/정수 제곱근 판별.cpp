#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long x = sqrt(n);
    if (x * x == n) return pow(x + 1, 2);
    return -1;
}