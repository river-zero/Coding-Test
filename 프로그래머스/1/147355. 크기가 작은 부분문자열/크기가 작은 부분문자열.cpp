#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int pSize = p.size();
    
    for (int i = 0; i <= t.size() - pSize; i++) {
        string str = t.substr(i, pSize);
        
        // p의 길이가 최대 18까지이므로 long long이 적절
        // 따라서 stoi 대신 stoll 사용
        long long strToInt = stoll(str);
        long long pToInt = stoll(p);
    
        if (strToInt <= pToInt) answer++;
    }
    
    return answer;
}