#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_zeros(vector<int>& lottos) {
    int count = 0;
    for (int num : lottos) {
        if (num == 0) count++;
    }
    return count;
}

int count_matches(vector<int>& lottos, vector<int>& win_nums) {
    int count = 0;
    for (int lotto_num : lottos) {
        for (int win_num : win_nums) {
            if (lotto_num == win_num) {
                count++;
                
                // 한 번 일치하는 숫자를 찾으면 중복 계산을 피하기 위해 종료
                break; 
            }
        }
    }
    return count;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int zeros = count_zeros(lottos);
    int matches = count_matches(lottos, win_nums);
    
    int max_rank = min(7 - (zeros + matches), 6); // 최고 순위
    int min_rank = min(7 - matches, 6);           // 최저 순위
    
    answer.push_back(max_rank);
    answer.push_back(min_rank);
    
    return answer;
}
