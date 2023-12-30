#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> m;
    
    for(int i = 0; i < s.size(); i++) {
        
        if(m.find(s[i]) == m.end()) {
            answer.push_back(-1); 
            m.insert({s[i], i});
        } else {
            answer.push_back(i - m[s[i]]);
            m[s[i]] = i;
        }
    }
    
    return answer;
}