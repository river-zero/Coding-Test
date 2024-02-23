#include <iostream>
#include <stack>

using namespace std;

bool IsValidPS(string ps) {
    stack<char> st;
    
    for (int i = 0; i < ps.size(); i++) {
        if (ps[i] == '(') {
            st.push(ps[i]);
        } else if (ps[i] == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }
    
    return st.empty();
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string ps;
        cin >> ps;
        
        if (IsValidPS(ps)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}