#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 에라토스테네스의 체로 소수 구하기
vector<int> getPrimes(int maxNum) {
    vector<bool> isPrime(maxNum + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= maxNum; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= maxNum; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> primes = getPrimes(N);

    int start = 0, end = 0, sum = 0, count = 0;

    // 투 포인터로 연속된 소수의 합 찾기
    while (true) {
        if (sum >= N) {
            sum -= primes[start++];
        } else if (end == primes.size()) {
            break;
        } else {
            sum += primes[end++];
        }
        if (sum == N) {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}
