#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

int main() {
    int n;
    cin >> n;
    
    vector<string> words;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        
        // 중복인지 확인하고 아니라면 단어 추가
        if (find(words.begin(), words.end(), word) == words.end()) {
            words.push_back(word);
        }
    }
    
    sort(words.begin(), words.end(), compare);
    
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << '\n';
    }
}