class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        
        int n = prices.size();
        std::vector<int> array(n + 1, 0);
        
        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = std::min(minPrice, prices[i]);
            array[i + 1] = std::max(array[i], prices[i] - minPrice);
        }
        
        return array[n];
    }
};