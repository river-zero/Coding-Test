#include <iostream>

using namespace std;

// 최대공약수
int gcd(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// 최소공배수
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;
    
    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl;
}
