#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = n + 1;
    int count = bitset<20>(n).count();
    
    while (count != bitset<20>(answer).count()) {
        answer++;
    }
    
    return answer;
}