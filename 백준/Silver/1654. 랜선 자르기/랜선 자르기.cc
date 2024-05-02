#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxLength(vector<int>& lines, int N, long long start, long long end) {
    long long result = 0;
    
    while (start <= end) {
        long long mid = (start + end) / 2;
        long long count = 0;
        
        for (int i = 0; i < lines.size(); i++) {
            count += lines[i] / mid;
        }
        
        if (count >= N) {
            result = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int K, N;
    cin >> K >> N;
    
    vector<int> lines(K);
    long long maxLen = 0;
    
    for (int i = 0; i < K; i++) {
        cin >> lines[i];
        maxLen = max(maxLen, (long long)lines[i]);
    }
    
    long long result = maxLength(lines, N, 1, maxLen);
    cout << result;
}