#include <iostream>

using namespace std;

int main() {
    while (true) {
        int A, B;
        cin >> A >> B;
        
        // 입력이 끝난 경우 루프 종료
        if (cin.eof()) break;
        
        cout << A + B << endl;
    }
}