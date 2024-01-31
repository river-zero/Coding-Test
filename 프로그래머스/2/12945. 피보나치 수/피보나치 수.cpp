#include <string>
#include <vector>

using namespace std;

int Fibonacci(int n, vector<int>& memo) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    
    if (memo[n] != -1) {
        return memo[n];
    }
    
    memo[n] = (Fibonacci(n - 2, memo) + Fibonacci(n - 1, memo)) % 1234567;
    return memo[n];
}

int solution(int n) {
    vector<int> memo(n + 1, -1);
    int answer = Fibonacci(n, memo);
    return answer;
}