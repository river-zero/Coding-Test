#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int count = 0;
    
    while (N >= 0) {
        if (N % 5 == 0) {
            count += N / 5;
            cout << count << endl;
            return 0;
        }
        
        N -= 3;
        count++;
    }
    
    cout << -1 << endl;
    
    return 0;
}