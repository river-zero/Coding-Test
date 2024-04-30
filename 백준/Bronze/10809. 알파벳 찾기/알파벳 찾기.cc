#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;
    
    int alphabet[26];
    fill(alphabet, alphabet + 26, -1);
    
    for (int i = 0; i < S.length(); i++) {
        int index = S[i] - 'a';
        if (alphabet[index] == -1) {
            alphabet[index] = i;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << ' ';
    }
}