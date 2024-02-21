#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, num;
    cin >> n;
    
    unordered_map<int, int> card;
    while (n--) {
        cin >> num;
        card[num]++;
    }
    
    cin >> m;
    while (m--) {
        cin >> num;
        cout << card[num] << " ";
    }
}