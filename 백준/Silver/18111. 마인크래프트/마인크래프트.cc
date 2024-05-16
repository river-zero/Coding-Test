#include <iostream>
#include <climits>
using namespace std;

const int MAX_SIZE = 500;

int main() {
    int N, M, B;
    cin >> N >> M >> B;
    
    int ground[MAX_SIZE][MAX_SIZE];
    int minHeight = INT_MAX;
    int maxHeight = INT_MIN;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ground[i][j];
            minHeight = min(minHeight, ground[i][j]);
            maxHeight = max(maxHeight, ground[i][j]);
        }
    }
    
    int minTime = INT_MAX;
    int resultHeight = 0;
    
    for (int height = minHeight; height <= maxHeight; height++) {
        int buildCount = 0;
        int removeCount = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int diff = ground[i][j] - height;
                if (diff > 0) {
                    removeCount += diff;
                } else if (diff < 0) {
                    buildCount -= diff;
                }
            }
        }
        
        if (removeCount + B >= buildCount) {
            int time = removeCount * 2 + buildCount;
            if (time <= minTime) {
                minTime = time;
                resultHeight = height;
            }
        }
    }
    
    cout << minTime << " " << resultHeight << endl;
    
    return 0;
}