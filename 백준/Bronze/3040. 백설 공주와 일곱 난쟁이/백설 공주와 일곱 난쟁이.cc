#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[9];
    int sum = 0;
    
    // 난쟁이들의 키를 입력받고 합을 계산
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + 9);
    
    // 전체에서 두 난쟁이의 키를 뺐을 때 100이 되면
    // 그 두 난쟁이들은 가짜에 해당
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k == i || k == j) continue;
                    cout << arr[k] << '\n';
                }
                return 0;
            }
        }
    }
}
