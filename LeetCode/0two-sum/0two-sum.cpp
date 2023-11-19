class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> m;
        std::vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            int dis = target - nums[i];
            
            if (m.find(dis) != m.end()) {
                result.push_back(m[dis]);
                result.push_back(i);
                return result;
            }
            
            m[nums[i]] = i;
        }
        
        return result;
    }
};