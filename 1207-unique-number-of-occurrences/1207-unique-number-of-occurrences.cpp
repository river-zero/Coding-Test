class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        
        // 각 숫자 횟수 기록
        for (int num : arr) {
            map[num]++;
        }
        
        unordered_set<int> set;
        
        // 맵에 기록한 횟수를 set에 추가
        for (const auto& occ : map) {
            // 횟수가 중복되면 false 반환
            if (!set.insert(occ.second).second) {
                return false;
            }
        }
        
        return true;
    }
};