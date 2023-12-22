#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

map<char, int> m;

int dateStringToInt(string date) {
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8));
    return (28 * 12 * y) + (28 * (m - 1)) + d;
    // 간편한 비교를 위한 정수 표현
}

int calcDate(int d, int num) {
    return d + (28 * num) - 1;
    // 유효기간을 계산하고 날짜를 28일 단위로 변환하여 반환
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int todayInt = dateStringToInt(today);

    // 약관별 유효기간을 맵에 저장
    for (string& t : terms) {
        istringstream iss(t);
        char cmd;
        int num;
        iss >> cmd >> num;
        m[cmd] = num;
    }

    // 각 개인정보에 대해 유효기간을 계산하고 오늘 날짜와 비교하여 파기 여부를 판단
    for (int i = 0; i < privacies.size(); i++) {
        istringstream iss(privacies[i]);
        string s;
        char cmd;
        iss >> s >> cmd;

        // 유효기간이 지났으면 번호를 벡터에 추가
        int dateInt = dateStringToInt(s);
        int expired = calcDate(dateInt, m[cmd]);
        if (expired < todayInt) answer.push_back(i + 1);
    }

    return answer;
}