class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 &&                                 // 현재 칸이 비어있음
               (i == 0 || flowerbed[i - 1] == 0) &&                  // 왼쪽에 꽃 없음
               (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) // 오른쪽에 꽃 없음
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        
        return count >= n;
    }
};