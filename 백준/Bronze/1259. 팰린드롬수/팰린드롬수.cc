#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsPalindrome(int num) {
    string str = to_string(num);
    string reversStr = str;
    
    reverse(reversStr.begin(), reversStr.end());
    
    return str == reversStr;
}

int main() {
    while (true) {
        int num;
        cin >> num;

        if (num == 0) break;

        if (IsPalindrome(num)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}