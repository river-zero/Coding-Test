class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        
        for (int e : nums) {
            result ^= e;
        }
        
        return result;
    }
};