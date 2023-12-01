#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> m{};
    
    for (int i = 0; i < name.size(); i++) {
        m[name[i]] = yearning[i];
    }
    
    for (int i = 0; i < photo.size(); i++) {
        int total = 0;
        
        for (const string person : photo[i]) {
            if (m.find(person) != m.end()) {
                total += m[person];
            }
        }
        
        answer.push_back(total);
    }
    
    return answer;
}