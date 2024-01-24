#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2, 0);

    long multiply = n * m;

    while (m != 0) {
        int keep = n % m;
        n = m;
        m = keep;
    }

    answer[0] = n;
    answer[1] = multiply / n;

    return answer;
}