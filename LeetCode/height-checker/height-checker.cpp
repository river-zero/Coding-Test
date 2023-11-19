class Solution {
public:
    int heightChecker(vector<int>& heights) {
        const int MAX     = 100;
        int freq[MAX + 1] = { 0 };
        int n             = heights.size();
        int count         = 0;
        int index         = 1;
        
        for (int i = 0; i < n; i++) {
            freq[heights[i]]++;
        }
        
        for (int i = 0; i < n; i++) {
            while (!freq[index]) {
                index++;
            }
            
            if (heights[i] != index) {
                count++;
            }
            
            freq[index]--;
        }
        
        return count;
    }
};