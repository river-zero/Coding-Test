#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    // sort 함수는 벡터나 배열과 같은 컨테이너에 사용
    // n을 문자열로 변환한 후에 정렬하고 다시 숫자로 변환 필요
    
    string str = to_string(n);
    sort(str.begin(), str.end(), greater<>());
    return stoll(str);
}