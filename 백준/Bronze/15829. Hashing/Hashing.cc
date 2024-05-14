#include <iostream>
#include <string>
using namespace std;

const int MOD = 1234567891;
const int BASE = 31;

int main() {
    int L;
    cin >> L;
    
    string str;
    cin >> str;
    
    long long hash_value = 0;
    long long pow_base = 1;
    
    for (int i = 0; i < L; i++) {
        hash_value = (hash_value + (str[i] - 'a' + 1) * pow_base) % MOD;
        pow_base = (pow_base * BASE) % MOD;
    }
    
    cout << hash_value << endl;
    
    return 0;
}