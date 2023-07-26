class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max = -1;
        
        for (int i = n - 1; i >= 0; i--) {
            int now = arr[i];
            arr[i] = max;
            
            if (now > max) {
                max = now;
            }
        }
        
        return arr;
    }
};