#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int empty = 1;
    int fresh = 0;
    
    while (true) {
        empty = (n / a) * a;
        fresh = (n / a) * b;
        
        if (!empty) break;
        
        answer += fresh;
        n += fresh - empty;
    }
    
    return answer;
}