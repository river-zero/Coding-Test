#include <iostream>
#include <algorithm>

using namespace std;

bool broken[10]; 

int possible(int c) {
    if (c == 0) {
        if (broken[0]) {
            return 0;
        } else {
            return 1;
        }
    }
    
    int len = 0;
    while (c > 0) {
        if (broken[c % 10]) {
            return 0;
        }
        len += 1;
        c /= 10;
    }
    
    return len;
}

int main(void) {
    int N, M; 
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        broken[x] = true;
    }

    int ans = abs(N - 100);
    for (int i = 0; i <= 1000000; i++) { 
        int c = i;
        int len = possible(c); 
        if (len > 0) {
            int press = abs(c - N); 
            if (ans > len + press) {
                ans = len + press;
            }
        }
    }
    cout << ans << '\n';
}
