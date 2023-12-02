class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // 용량 계산 및 업데이트
            int h = min(height[left], height[right]);
            int w = right - left;
            water = max(water, h * w);
            
            // 높이가 작은 포인터를 이동
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return water;
    }
};
