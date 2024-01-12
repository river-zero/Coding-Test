#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getDivisor(int num) {
    int count = 0;
    int sqrtNum = sqrt(num);
    for (int i = 1; i <= sqrtNum; i++) {
        if (num % i == 0) {
            if (i == num / i) count++;
            else count += 2;
        }
    }
    return count;
}

int solution(int left, int right) {
    int answer = 0;
    
    while (left <= right) {
        if (getDivisor(left) % 2 == 0) answer += left;
        else answer -= left;
        left++;
    }
    
    return answer;
}