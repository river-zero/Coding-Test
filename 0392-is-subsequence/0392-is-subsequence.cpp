class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPtr = 0;
        int tPtr = 0;
        
        while (sPtr < s.size() && tPtr < t.size()) {
            if (s[sPtr] == t[tPtr]) {
                // 문자가 일치하면 sPtr 증가
                sPtr++;
            }
            // tPtr은 항상 증가
            tPtr++;
        }
        
        // sPtr이 모두 있다면 부분 순서에 해당
        return sPtr == s.size();
    }
};