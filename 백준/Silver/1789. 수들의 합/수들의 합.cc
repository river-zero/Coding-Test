#include <iostream>

using namespace std;

int main() {
    unsigned long long s;
    cin >> s;
    
    unsigned long long sum = 0;
    int n = 0;
    
    while (sum <= s) {
        n++;
        sum += n;
    }
    
    cout << n - 1;
}