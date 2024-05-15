#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<int> difficulties;
    
    for (int i = 0; i < n; i++) {
        int difficulty;
        cin >> difficulty;
        difficulties.push_back(difficulty);
    }
    
    sort(difficulties.begin(), difficulties.end());
    
    int exclude = round(n * 0.15);
    int sum = 0;
    
    for (int i = exclude; i < n - exclude; i++) {
        sum += difficulties[i];
    }
    
    int average = round((double)sum / (n - 2 * exclude));
    
    cout << average << endl;
    
    return 0;
}