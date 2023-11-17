class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int count = 0;
        
        while (diff != 0) {
            count += diff & 1;
            diff >>= 1;
        }
        
        return count;
    }
};