class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int startIndex = 0;
        int maxLength = 1;
        
        if (s.empty()) return ""; // 비었다면 빈 문자열 반환
        if (n == 1) return s;     // 길이가 1이면 그대로 반환
        
        for (int i = 0; i < n;) {
            // 남은 문자열의 길이가 찾은 최대 길이의 절반보다 작으면 중단
            if (n - i <= maxLength / 2) break;
            
            int left = i;
            int right = i;
            
            // 중복 문자열은 빠르게 건너뛰기
            while (right < n - 1 && s[right + 1] == s[right]) right++;
            i = right + 1;
            
            // 가운데에서 퍼지면서 펠린드롬 검사
            while (right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                right++;
                left--;
            }
            int count = right - left + 1;
            
            if (count > maxLength) {
                startIndex = left;
                maxLength = count;
            }
        }
        
        return s.substr(startIndex, maxLength);
    }
};