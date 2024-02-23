#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    vector<int> data;
    
public:
    void push(int x) {
        data.push_back(x);
    }
    
    int pop() {
        if (empty()) return -1;
        int x = data.back();
        data.pop_back();
        return x;
    }
    
    int size() {
        return data.size();
    }
    
    bool empty() {
        return data.empty();
    }
    
    int top() {
        if (empty()) return -1;
        return data.back();
    }
};

int main() {
    Stack s;
    int N;
    cin >> N;
    
    while (N--) {
        string command;
        cin >> command;
        
        if (command == "push") {
            int x;
            cin >> x;
            s.push(x);
        } else if (command == "pop") {
            cout << s.pop() << endl;
        } else if (command == "size") {
            cout << s.size() << endl;
        } else if (command == "empty") {
            if (s.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        } else if (command == "top") {
            cout << s.top() << endl;
        }
    }
}