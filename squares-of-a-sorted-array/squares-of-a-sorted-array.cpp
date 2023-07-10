class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i{}; i < nums.size(); i++) {
            nums[i] *= nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        return nums;
    }
};

/*-------------------------------------------------------------
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left  = 0;
        int right = nums.size() - 1;
        int index = nums.size() - 1;

        while (left <= right) {
            int leftSquare  = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                result[index] = leftSquare;
                left++;
            } else {
                result[index] = rightSquare;
                right--;
            }
            
            index--;
        }

        return result;
    }
};
-------------------------------------------------------------*/