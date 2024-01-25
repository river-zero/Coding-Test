#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while (s != "1") {
        int count = 0;
        int index = 0;
        
        for (char c : s) {
            if (c == '1') count++;
        }
        
        answer[0]++;
        answer[1] += s.size() - count;
        
        // 이진 변환하고 불필요한 0을 제거
        s = bitset<32>(count).to_string();
        for (; index < 32; index++) {
            if (s[index] == '1') break;
        }
        s = s.substr(index);
    }
    
    return answer;
}