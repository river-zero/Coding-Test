class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> rec1, rec2;
        vector<vector<int>> ret(2, vector<int>());

        for (const int& num: nums1) {
            if (rec1.count(num) == 0)
                rec1[num] = true;
        }
        for (const int& num: nums2) {
            if (rec2.count(num) == 0)
                rec2[num] = true;
        }

        for (const auto& [key, value]: rec1) {
            if (rec2.count(key) == 0) {
                ret[0].push_back(key);
            }
        }
        for (const auto& [key, value]: rec2) {
            if (rec1.count(key) == 0) {
                ret[1].push_back(key);
            }
        }

        return ret;
    }
};