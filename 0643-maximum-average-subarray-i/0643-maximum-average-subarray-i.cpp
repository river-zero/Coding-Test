class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        // 초기 최댓값 설정
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;

        // 한 칸씩 옆으로 이동하면서 최댓값 업데이트
        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = std::max(maxSum, sum);
        }

        return static_cast<double>(maxSum) / k;
    }
};