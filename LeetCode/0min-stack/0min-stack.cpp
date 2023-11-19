class MinStack {
private:
    std::stack<std::pair<int, int>> pair;

public:
    MinStack() {

    }

    void push(int value) {
        if (pair.empty()) {
            pair.push({value, value});
        } else {
            int currMin = pair.top().second;
            pair.push({value, std::min(value, currMin)});
        }
    }

    void pop() {
        pair.pop();
    }

    int top() {
        return pair.top().first;
    }

    int getMin() {
        return pair.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */