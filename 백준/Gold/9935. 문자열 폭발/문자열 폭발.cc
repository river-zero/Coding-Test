#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str, bomb;
    cin >> str >> bomb;

    vector<char> result;
    int bombLen = bomb.size();

    for (char ch : str) {
        result.push_back(ch);

        // 폭발 문자열의 길이만큼 벡터를 체크
        if (result.size() >= bombLen) {
            bool isBomb = true;

            // 벡터의 가장 최근 bombLen 길이의 문자열이 폭발 문자열과 같은지 확인
            for (int i = 0; i < bombLen; ++i) {
                if (result[result.size() - bombLen + i] != bomb[i]) {
                    isBomb = false;
                    break;
                }
            }

            if (isBomb) {
                // 폭발 문자열이 맞다면 최근 bombLen 길이만큼 제거
                for (int i = 0; i < bombLen; ++i) {
                    result.pop_back();
                }
            }
        }
    }

    // 결과 벡터를 문자열로 변환
    if (result.empty()) {
        cout << "FRULA" << endl;
    } else {
        for (char ch : result) {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}
