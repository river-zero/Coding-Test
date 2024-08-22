#include <iostream>
using namespace std;

long long countOnes(long long x) {
    long long count = 0, factor = 1;
    while (factor <= x) {
        long long higher = x / (factor * 2) * factor;
        long long remainder = x % (factor * 2);
        count += higher;
        if (remainder >= factor) {
            count += remainder - factor + 1;
        }
        factor *= 2;
    }
    return count;
}

int main() {
    long long A, B;
    cin >> A >> B;
    cout << countOnes(B) - countOnes(A - 1) << "\n";
    return 0;
}
