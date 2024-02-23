#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    vector<int> data;

public:
    void push(int x) {
        data.push_back(x);
    }

    int pop() {
        if (empty()) return -1;
        int x = data.front();
        data.erase(data.begin());
        return x;
    }

    int size() {
        return data.size();
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
};

int main() {
    Queue q;
    int N;
    cin >> N;

    while (N--) {
        string command;
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            q.push(x);
        } else if (command == "pop") {
            cout << q.pop() << endl;
        } else if (command == "size") {
            cout << q.size() << endl;
        } else if (command == "empty") {
            if (q.empty()) cout << 1 << endl;
            else cout << 0 << endl;
        } else if (command == "front") {
            cout << q.front() << endl;
        } else if (command == "back") {
            cout << q.back() << endl;
        }
    }
}
