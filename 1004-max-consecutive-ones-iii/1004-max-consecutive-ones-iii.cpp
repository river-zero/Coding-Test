class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int zeroCount = 0;
        int maxOnes = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            // 0의 개수가 k보다 많으면
            // 왼쪽 인덱스를 이동해 크기를 조절
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxOnes = max(maxOnes, right - left + 1);
        }

        return maxOnes;
    }
};