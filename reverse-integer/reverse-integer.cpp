/*---------------------------------------
class Solution {
public:
    int reverse(int x) {
        int reversed = 0;

        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && pop < -8)) {
                return 0;
            }

            reversed = reversed * 10 + pop;
        }

        return reversed;
    }
};
---------------------------------------*/

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        
        std::string str = std::to_string(x);
        
        bool isNegative = (x < 0);
        if (isNegative) {
            str = str.substr(1);
        }
        std::reverse(str.begin(), str.end());
        
        try {
            int result = std::stoi(str);
            return isNegative ? -result : result;
        } catch (std::out_of_range) {
            return 0;
        }
    }
};