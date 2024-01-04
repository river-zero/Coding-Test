#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> giftIndex;
    map<string, int> giftCount;
    int n = friends.size();
    vector<vector<int>> giftTable(n, vector<int>(n, 0));
    vector<int> nextMonth(n, 0);
    
    // 이름과 인덱스를 매핑
    for (int i = 0; i < n; i++) {
        giftIndex[friends[i]] = i;
    }
    
    // 주고 받은 기록으로 선물 지수 계산
    for (string gift : gifts) {
        int give = giftIndex[gift.substr(0, gift.find(' '))];
        int take = giftIndex[gift.substr(gift.find(' ') + 1)];
        giftTable[give][take]++;
        giftCount[friends[give]]++;
        giftCount[friends[take]]--;
    }
    
    // 다음 달에 각 친구가 받을 선물수 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (giftTable[i][j] > giftTable[j][i] || (giftTable[i][j] == giftTable[j][i] && giftCount[friends[i]] > giftCount[friends[j]])) {
                nextMonth[i]++;
            }
        }
    }
    
    answer = *max_element(nextMonth.begin(), nextMonth.end());
    return answer;
}