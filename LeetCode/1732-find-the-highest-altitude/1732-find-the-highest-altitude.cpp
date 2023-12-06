class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAltitude = 0;
        int maxAltitude = 0;
        
        for (int gainValue : gain) {
            currAltitude += gainValue;
            maxAltitude = max(maxAltitude, currAltitude);
        }
        
        return maxAltitude;
    }
};