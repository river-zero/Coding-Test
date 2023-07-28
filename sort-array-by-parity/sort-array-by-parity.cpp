class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            if (nums[left] % 2 != 0) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                
                right--;
            } else {
                left++;
            }
        }
        
        return nums;
    }
};