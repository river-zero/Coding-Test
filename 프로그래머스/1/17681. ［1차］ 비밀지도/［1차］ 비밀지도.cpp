#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, string(n, ' '));
    
    // 어느 하나라도 벽이면 전체 지도에서 벽
    for (int i = 0; i < n; i++) {
        arr1[i] = arr1[i] | arr2[i];
    }
    
    for (int i = 0; i < n; i++) {
        // 정수를 이진수 문자열로 바꾸고 필요없는 비트 제거
        string line = bitset<16>(arr1[i]).to_string().substr(16 - n);
        
         for (int j = 0; j < n; j++) {
             if (line[j] == '1') answer[i][j] = '#';
         }
    }
    
    return answer;
}