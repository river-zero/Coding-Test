#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int num = 666;
    int count = 1;
    
    while (count < N) {
        num++;
        int temp = num;
        while (temp > 0) {
            if (temp % 1000 == 666) {
                count++;
                break;
            }
            temp /= 10;
        }
    }
    
    cout << num;
}