#include <iostream>
#include <limits>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    // min에는 최댓값으로 max에는 최솟값으로 초기화
    int min = numeric_limits<int>::max();
    int max = numeric_limits<int>::min();
    
    while (N--) {
        int num;
        cin >> num;
        
        if (num < min) min = num;
        if (num > max) max = num;
    }

    cout << min << " " << max << endl;
}