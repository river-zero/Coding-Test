#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    map<int, int> mX;
    map<int, int> mY;
    
    // 맵에 각 숫자의 개수를 저장
    for (int i  = 0; i < X.size(); i++) mX[X[i] - '0']++;
    for (int i  = 0; i < Y.size(); i++) mY[Y[i] - '0']++;
    
    // 9부터 0까지 순환
    for (int i = 9; i >= 0; i--) {
        // 가장 적은 개수를 추가
        int num = min(mX[i], mY[i]);
        for (int j = 0; j < num; j++) {
            answer += static_cast<char>(i + '0');
        }
    }
    
    if (answer == "") return "-1";
    else if (answer[0] == '0') return "0";
    else return answer;
}