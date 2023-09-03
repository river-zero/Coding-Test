class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int total{}, max{};
        
        for (int i{}; i < nums.size(); i++) {
            if (nums[i] == 1) {
                total++;
            } else {
                if (total > max) {
                    max = total;
                }
                total = 0;
            }
        }
        return total > max ? total : max;
    }
};