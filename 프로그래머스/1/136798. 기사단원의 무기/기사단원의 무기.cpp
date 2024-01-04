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

int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; i++) {
        int divisor = getDivisor(i);
        if (divisor > limit) {
            answer += power;
        } else {
            answer += divisor;
        }
    }
    
    return answer;
}