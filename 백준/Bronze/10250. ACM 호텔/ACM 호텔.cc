#include <iostream>

using namespace std;

int main() {
    int T, H, W, N;
    cin >> T;
    
    while (T--) {
        cin >> H >> W >> N;
        
        int floor = N % H;
        int room = N / H + 1;
        
        if (floor == 0) {
            floor = H;
            room--;
        }
        
        printf("%d%02d\n", floor, room);
    }
}