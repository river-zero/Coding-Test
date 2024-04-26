#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        string s;
        cin >> s;

        int score = 0;
        int count = 0;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'O') {
                count++;
                score += count;
            } else {
                count = 0;
            }
        }

        cout << score << endl;
    }
}
