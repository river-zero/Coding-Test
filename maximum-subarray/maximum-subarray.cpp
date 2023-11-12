class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int nowSum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            nowSum = std::max(nums[i], nowSum + nums[i]);
            maxSum = std::max(maxSum, nowSum);
        }
        
        return maxSum;
    }
};