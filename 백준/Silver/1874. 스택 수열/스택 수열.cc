#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;
    vector<char> result;
    int current = 1;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        while (current <= num) {
            st.push(current);
            result.push_back('+');
            current++;
        }

        if (st.top() == num) {
            st.pop();
            result.push_back('-');
        } else {
            cout << "NO";
            return 0;
        }
    }

    for (char c : result) {
        cout << c << '\n';
    }
}