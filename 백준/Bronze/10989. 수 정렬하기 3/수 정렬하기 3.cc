#include <iostream>
using namespace std;

const int MAX_NUM = 10000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int count[MAX_NUM + 1] = {0};
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        count[num]++;
    }
    
    for (int i = 1; i <= MAX_NUM; i++) {
        for (int j = 0; j < count[i]; j++) {
            cout << i << '\n';
        }
    }
    
    return 0;
}