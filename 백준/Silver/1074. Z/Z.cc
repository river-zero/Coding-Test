#include <iostream>
#include <cmath>

using namespace std;

int DrawZ(int N, int r, int c) {
    if (N == 0) return 0;
    
    // 2의 N-1승
    int half = 1 << (N - 1);
    
    // 순서대로 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 
    if (r < half && c < half) return DrawZ(N - 1, r, c);
    if (r < half && c >= half) return half * half + DrawZ(N - 1, r, c - half);
    if (r >= half && c < half) return 2 * half * half + DrawZ(N - 1, r - half, c);
    return 3 * half * half + DrawZ(N - 1, r - half, c - half);
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    
    cout << DrawZ(N, r, c) << endl;
}
