class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstMinNum = INT_MAX;
        int secondMinNum = INT_MAX;
        
        for (auto num : nums) {
            if (num <= firstMinNum) {
                firstMinNum = num;
            } else if (num <= secondMinNum) {
                secondMinNum = num;
            } else {
                return true;
            }
        }
        
        return false;
    }
};