class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
     
        for (char c : s) {
            // 여는 괄호를 만난 경우
            if (map.find(c) != map.end()) {
                stack.push(c);
            // 닫는 괄호를 만난 경우
            } else {
                // 스택이 비었거나
                // 괄호가 일치하지 않는 경우 false
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