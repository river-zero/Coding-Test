#include <iostream>
using namespace std;

int getResidentCount(int k, int n) {
    if (k == 0) {
        return n;
    }
    
    if (n == 1) {
        return 1;
    }
    
    return getResidentCount(k - 1, n) + getResidentCount(k, n - 1);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int k, n;
        cin >> k >> n;
        
        int count = getResidentCount(k, n);
        cout << count << endl;
    }
    
    return 0;
}