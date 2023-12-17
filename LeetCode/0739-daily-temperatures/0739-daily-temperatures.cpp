class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int prevIndex = stk.top();
                stk.pop();
                result[prevIndex] = i - prevIndex;
            }
            stk.push(i);
        }

        return result;
    }
};