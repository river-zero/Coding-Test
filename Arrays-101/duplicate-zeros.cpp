/*---------------------------------------------------
    https://leetcode.com/problems/duplicate-zeros
---------------------------------------------------*/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        
        for (int i{}; i < size; i++) {
            if (arr[i] == 0) {
                for (int j{ size - 1 }; j > i; j--) {
                    arr[j] = arr[j - 1];
                }
                i++;
            }
        }
    }
};