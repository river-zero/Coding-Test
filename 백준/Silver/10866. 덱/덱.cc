#include <iostream>
#include <vector>

using namespace std;

class Deque {
private:
    vector<int> data;
    
public:
    void push_front(int x) {
        data.insert(data.begin(), x);
    }
    
    void push_back(int x) {
        data.push_back(x);
    }
    
    int pop_front() {
        if (empty()) return -1;
        int x = data.front();
        data.erase(data.begin());
        return x;
    }
    
    int pop_back() {
        if (empty()) return -1;
        int x = data.back();
        data.pop_back();
        return x;
    }
    
    bool empty() {
        return data.empty();
    }

    int front() {
        if (empty()) return -1;
        return data.front();
    }

    int back() {
        if (empty()) return -1;
        return data.back();
    }

    int size() {
        return data.size();
    }
};

int main() {
    Deque dq;
    int N;
    cin >> N;

    while (N--) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        } else if (command == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        } else if (command == "pop_front") {
            cout << dq.pop_front() << endl;
        } else if (command == "pop_back") {
            cout << dq.pop_back() << endl;
        } else if (command == "size") {
            cout << dq.size() << endl;
        } else if (command == "empty") {
            if (dq.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        } else if (command == "front") {
            cout << dq.front() << endl;
        } else if (command == "back") {
            cout << dq.back() << endl;
        }
    }
}