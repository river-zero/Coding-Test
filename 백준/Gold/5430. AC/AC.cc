#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        deque<int> dq;
        string num;
        for (char c : arr) {
            if (isdigit(c)) {
                num += c;
            } else if (!num.empty()) {
                dq.push_back(stoi(num));
                num.clear();
            }
        }

        bool reversed = false;
        bool error = false;

        for (char command : p) {
            if (command == 'R') {
                reversed = !reversed;
            } else if (command == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (reversed) {
                    dq.pop_back();
                } else {
                    dq.pop_front();
                }
            }
        }

        if (error) {
            cout << "error" << endl;
        } else {
            cout << "[";
            if (!dq.empty()) {
                if (reversed) {
                    for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                        cout << *it;
                        if (it != dq.rend() - 1) {
                            cout << ",";
                        }
                    }
                } else {
                    for (auto it = dq.begin(); it != dq.end(); ++it) {
                        cout << *it;
                        if (it != dq.end() - 1) {
                            cout << ",";
                        }
                    }
                }
            }
            cout << "]" << endl;
        }
    }

    return 0;
}