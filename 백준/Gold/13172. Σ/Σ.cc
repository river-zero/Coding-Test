#include <iostream>
#define MOD 1000000007

using namespace std;

long long mod_exp(long long a, long long b, long long mod) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

long long mod_inverse(long long a, long long mod) {
    return mod_exp(a, mod - 2, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    long long result = 0;

    for (int i = 0; i < M; ++i) {
        long long N, S;
        cin >> N >> S;
        long long inverse_N = mod_inverse(N, MOD);
        result = (result + (S * inverse_N) % MOD) % MOD;
    }

    cout << result << '\n';

    return 0;
}
