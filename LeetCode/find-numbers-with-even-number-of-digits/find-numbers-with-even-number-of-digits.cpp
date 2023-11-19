class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int num{}, count{};
        
        for (int i{}; i < nums.size(); i++) {
            int temp{ nums[i] };
            
            while (temp > 0) {
                temp = temp / 10;
                num++;
            }
            
            if (num % 2 == 0) {
                count++;
            }
            
            num = 0;
        }
        
        return count;
    }
};