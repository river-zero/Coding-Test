/*----------------------------------------------
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t find = haystack.find(needle);
        if (find != std::string::npos) {
            return static_cast<int>(find);
        }
        return -1;
    }
};
----------------------------------------------*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        // 빈 문자열 입력
        if (n == 0) {
            return 0;
        }
        
        for (int i = 0; i <= m - n; i++) {
            int j;
            
            for (j = 0; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            
            // 끝까지 비교 완료
            if (j == n) {
                return i;
            }
        }
        
        return -1;
    }
};