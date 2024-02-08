#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    int sqrt_n = sqrt(n);
    for (int i = 2; i <= sqrt_n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<pair<string, int>> v;
    
    // 진법 변환
    string s = "";
    while (n > 0) {
        s += to_string(n % k);
        n /= k;
    }
    reverse(s.begin(), s.end());
    
    string temp = "";
    for (char c : s) {
        if (c == '0') {
            if (!temp.empty() && isPrime(stoll(temp))) {
                answer++;
            }
            temp = "";
        } else {
            temp += c;
        }
    }
    
    if (!temp.empty() && isPrime(stoll(temp))) {
        answer++;
    }
    
    return answer;
}