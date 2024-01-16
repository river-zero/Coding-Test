#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int n = s.size();
    return s.substr(n / 2 - (n % 2 == 0 ? 1 : 0), 2 - n % 2);
}