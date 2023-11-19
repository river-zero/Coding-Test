class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> result;
        
        for (int e : nums1) {
            count[e]++;
        }
        
        for (int e : nums2) {
            if (count.find(e) != count.end() && count[e] > 0) {
                result.push_back(e);
                count[e]--;
            }
        }
        
        return result;
    }
};