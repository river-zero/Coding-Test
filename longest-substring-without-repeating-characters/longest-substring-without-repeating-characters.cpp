class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> charSet;
        int maxLength = 0;
        int left = 0;
        int right = 0;

        while (right < n) {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                charSet.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};