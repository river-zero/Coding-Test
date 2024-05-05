#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
vector<bool> isPrime(MAX + 1, true);

void eratosthenes() {
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    eratosthenes();

    for (int i = M; i <= N; i++) {
        if (isPrime[i]) {
            cout << i << '\n';
        }
    }
}