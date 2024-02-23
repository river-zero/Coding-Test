#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    
    while (cin >> a >> b >> c && a != 0 && b != 0 && c != 0) {
        long n1 = a * a;
        long n2 = b * b;
        long n3 = c * c;
        
        if (n1 == n2 + n3 || n2 == n1 + n3 || n3 == n1 + n2) {
            cout << "right" << "\n";
        } else {
            cout << "wrong" << "\n";
        }
    }
}