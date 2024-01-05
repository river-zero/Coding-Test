#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = { -1 };
    
    for(int c : ingredient) {
        if(v.back() == 1 && c == 2) v.back() = 12;
        else if(v.back() == 12 && c == 3) v.back() = 123;
        else if(v.back() == 123 && c == 1) answer++, v.pop_back();
        else v.push_back(c);
    }    

    return answer;
}