#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    map<string, int> unheard;
    string name;
    for (int i = 0; i < N; i++) {
        cin >> name;
        unheard[name]++;
    }
    
    vector<string> unheardUnseen;
    for (int i = 0; i < M; i++) {
        cin >> name;
        if (unheard[name] > 0) unheardUnseen.push_back(name);
    }
    
    sort(unheardUnseen.begin(), unheardUnseen.end());
    cout << unheardUnseen.size() << '\n';
    for (const string &person : unheardUnseen) {
        cout << person << '\n';
    }
}
