#include <string>
#include <vector>

using namespace std;

int GetSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool solution(int x) {
    if (x % GetSum(x) == 0) return true;
    return false;
}