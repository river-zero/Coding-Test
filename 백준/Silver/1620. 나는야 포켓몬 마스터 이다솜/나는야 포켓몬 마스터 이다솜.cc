#include <iostream>
#include <map>
#include <cctype>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    map<string, int> monsterName;
    map<int, string> monsterNum;
    
    int num = 1;
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;
        monsterName[name] = num;
        monsterNum[num++] = name;
    }
    
    for (int i = 0; i < M; i++) {
        char question[21];
		cin >> question;
        
        if (isdigit(question[0])) {
            int idx = stoi(question);
            cout << monsterNum[idx] << '\n';
        } else {
            string name = question;
            cout << monsterName[name] << '\n'; 
        }
    }
}
