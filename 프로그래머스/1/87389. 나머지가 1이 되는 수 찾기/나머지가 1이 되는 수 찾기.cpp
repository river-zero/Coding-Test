#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int x = n - 1; x > 0; x--) {
        if (n % x == 1) answer = x;
    }
    
    return answer;
}