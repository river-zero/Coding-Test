class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        int prevLength = 0;
        int zeroIndex = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                prevLength++;
            } else {
                prevLength = i - zeroIndex;
                zeroIndex = i;
            }

            maxLength = max(maxLength, prevLength);
        }

        // 배열에 0이 없는 경우
        if (zeroIndex == -1) {
            return n - 1;
        }

        return maxLength - 1;
    }
};