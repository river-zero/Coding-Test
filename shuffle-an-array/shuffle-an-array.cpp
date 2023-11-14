class Solution {
private:
    std::vector<int> original;
    std::vector<int> shuffled;
    std::mt19937 gen;

public:
    Solution(std::vector<int>& nums) 
        : original(nums), shuffled(nums), gen(std::random_device{}()) {
    }

    std::vector<int> reset() {
        return original;
    }

    std::vector<int> shuffle() {
        std::vector<int> temp = shuffled;
        
        for (int i = temp.size() - 1; i > 0; --i) {
            std::uniform_int_distribution<int> dist(0, i);
            int j = dist(gen);
            std::swap(temp[i], temp[j]);
        }
        
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */