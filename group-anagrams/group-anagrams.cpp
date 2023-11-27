class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& str : strs) {
            // 문자열을 정렬
            string sortStr = str;
            sort(sortStr.begin(), sortStr.end());
            
            // 정렬한 문자열을 키로 써서 맵에 추가
            anagramGroups[sortStr].push_back(str);
        }
        
        vector<vector<string>> result;
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }
        return result;
    }
};