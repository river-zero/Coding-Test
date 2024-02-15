#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int R;
        string S;
        
        // 다음 문자열로 재활용 위해 초기화
        string P = "";
        
        cin >> R >> S;
        
        for (char c : S) {
            P += string(R, c);
        }
        
        cout << P << endl;
    }
}