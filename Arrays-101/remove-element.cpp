/*--------------------------------------------------
    https://leetcode.com/problems/remove-element
--------------------------------------------------*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        
        for (int j{}; j < n; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        
        return i;
    }
};