#include <iostream>
#include <string>

using namespace std;

char arr[64][64];

string quadtree(int x, int y, int n) {
    if (n == 1) {
        return string(1, arr[x][y]);
    }
    
    string result = "(";
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (arr[i][j] != arr[x][y]) {
                int m = n / 2;
                result += quadtree(x, y, m);
                result += quadtree(x, y + m, m);
                result += quadtree(x + m, y, m);
                result += quadtree(x + m, y + m, m);
                return result + ")";
            }
        }
    }
    
    return string(1, arr[x][y]);
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << quadtree(0, 0, n);
}
