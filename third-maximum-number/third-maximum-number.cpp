class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first  = LLONG_MIN; // 오버플로우나 범위 문제 방지
        long long second = LLONG_MIN;
        long long third  = LLONG_MIN;
        
        for (int num : nums) {
            if (num == first || num == second || num == third) {
                continue;
            }
            
            if (num > first) {
                third  = second;
                second = first;
                first  = num;
            } else if (num > second) {
                third  = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }
        
        if (third == LLONG_MIN) {
            return first;
        }
        return third;
    }
};
