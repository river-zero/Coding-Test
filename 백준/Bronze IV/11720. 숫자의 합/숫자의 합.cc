#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string nums;
    cin >> nums;
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // 문자열을 정수로 바꿔서 더함
        sum += nums[i] - '0';
    }
    
    cout << sum;
}