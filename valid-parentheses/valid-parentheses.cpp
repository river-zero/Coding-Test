class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
     
        for (char c : s) {
            // 괄호가 있는 경우
            if (map.find(c) != map.end()) {
                stack.push(c);
            // 괄호가 없는 경우
            } else {
                if (stack.empty() || map[stack.top()] != c) {
                    return false;
                }
                stack.pop();
            }
        }
        
        // 남은 괄호가 없다면 true
        return stack.empty();
    }
};