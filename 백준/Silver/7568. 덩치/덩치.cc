#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> people(N);
    
    for (int i = 0; i < N; i++) {
        cin >> people[i].first >> people[i].second;
    }
    
    for (int i = 0; i < N; i++) {
        int rank = 1;
        
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            
            if (people[i].first < people[j].first && people[i].second < people[j].second) {
                rank++;
            }
        }
        
        cout << rank << " ";
    }
    
    return 0;
}