#include <iostream>
#include <vector>

using namespace std;

// 에라토스테네스의 체 알고리즘
bool IsPrime(int num) {
    if (num <= 1) return false;
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    int count = 0;
    while (n--) {
        int input;
        cin >> input;
        if (IsPrime(input)) count++;
    }
    cout << count;
}