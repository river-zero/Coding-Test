class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int count = 1;
        int index = 0;
        
        if (n <= 1) return n;
        
        for (int i = 1; i < n; i++) {
            if (chars[i] == chars[i - 1]) {
                // 현재 문자와 이전 문자가 같으면 count 증가
                count++;
            } else {
                // 다르다면 chars에 압축 결과 저장
                chars[index++] = chars[i - 1];
                
                // 숫자를 string으로 변환해 저장
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[index++] = c;
                    }
                }
                
                count = 1;
            }
        }
        
        // 마지막 문자 처리
        chars[index++] = chars[n - 1];
        if (count > 1) {
            string countStr = to_string(count);
            for (char c: countStr) {
                chars[index++] = c;
            }
        }
        
        return index;
    }
};