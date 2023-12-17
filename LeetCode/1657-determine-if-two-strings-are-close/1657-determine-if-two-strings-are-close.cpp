class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }

        unordered_map<char, int> freq1, freq2;

        for (char c : word1) {
            freq1[c]++;
        }

        for (char c : word2) {
            freq2[c]++;
        }

        if (freq1.size() != freq2.size()) {
            return false;
        }

        vector<int> counts1, counts2;

        for (auto& entry : freq1) {
            counts1.push_back(entry.second);
        }

        for (auto& entry : freq2) {
            if (freq1.find(entry.first) == freq1.end()) {
                return false;
            }
            counts2.push_back(entry.second);
        }

        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());

        return counts1 == counts2;
    }
};