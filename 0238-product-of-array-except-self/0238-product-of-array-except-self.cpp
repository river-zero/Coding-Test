class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // 왼쪽 모두 곱하기
        int left = 1;
        for (int i = 1; i < n; i++) {
            left *= nums[i - 1];
            result[i] = left;
        }
        
        // 오른쪽 모두 곱하기
        int right = 1;
        for (int i = n - 2; i >= 0; i--) {
            right *= nums[i + 1];
            result[i] *= right;
        }
            
        return result;
    }
};