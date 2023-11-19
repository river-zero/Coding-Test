class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        
        // 공백이 있는 경우
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // 부호가 있는 경우
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        long result = 0;
        while (i < n && isdigit(s[i])) { // 숫자인지 확인
            // 각 문자를 변환해 result에 누적
            result = result * 10 + (s[i] - '0');
            i++;
            
            // 범위를 벗어나는 경우
            if (result * sign < INT_MIN) {
                return INT_MIN;
            } else if (result * sign > INT_MAX) {
                return INT_MAX;
            }
        }
        
        return result * sign;
    }
};