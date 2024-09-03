#include <iostream>
#include <algorithm>
using namespace std;

int N;              
int num[10];        
int fruit[200000];  

bool checkCnt() {
    int cnt = 0;
    for (int i = 1; i < 10; i++) {
        if (num[i] > 0) cnt++;
        if (cnt > 2) return false;
    }
    return true;
}

int makeTanghulu() {
    int left = 0;
    int right = 0;
    int result = 0;

    while (left < N) {
        while (right < N) {
            num[fruit[right++]]++;
            if (!checkCnt()) {
                right--;
                num[fruit[right]]--;
                break;
            }
        }
        result = max(result, right - left);
        num[fruit[left++]]--;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> fruit[i];

    cout << makeTanghulu() << '\n';

    return 0;
}
