#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

void getElements(string str, unordered_map<string, int> &um) {
    // 대소문자를 가리지 않고 모두 소문자로 변경
    for (auto &c : str) c = tolower(c);
    
    for (int i = 0; i < str.size() - 1; i++) {
        // 두 글자를 추출하기 때문에 다음 문자도 알파벳인지 확인
        if (!isalpha(str[i]) || !isalpha(str[i + 1]) || isspace(str[i]) || isspace(str[i + 1])) continue;
        
        // 두 글자를 추출하여 데이터 저장
        um[str.substr(i, 2)]++;
    }
}

int solution(string str1, string str2) {
    int inter_str = 0;
    int union_str = 0;
    unordered_map<string, int> um_str1;
    unordered_map<string, int> um_str2;
    
    // 각 문자열에서 두 글자씩 추출하여 빈도수 계산
    getElements(str1, um_str1);
    getElements(str2, um_str2);
    
    // 교집합 계산
    for (auto element : um_str1) {
        if (um_str2[element.first]) {
            inter_str += min(element.second, um_str2[element.first]);
            
            // 합집합 계산을 위해 최대 개수 저장
            um_str2[element.first] = max(element.second, um_str2[element.first]);
        } else {
            um_str2[element.first] = element.second;
        }
    }
    
    // 합집합 계산
    for (auto element : um_str2) {
        union_str += element.second;
    }
    
    // 합집합이 0인 경우 예외 처리
    if (!union_str) return 65536;
    
    // 자카드 유사도 계산
    return floor(inter_str * 65536 / union_str);
}
