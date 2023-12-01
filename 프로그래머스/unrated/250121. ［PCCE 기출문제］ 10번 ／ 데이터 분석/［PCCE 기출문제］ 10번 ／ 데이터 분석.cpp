#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> m = {{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}};
    int ext_index = m[ext];
    int sort_index = m[sort_by];
    
    for (int i = 0; i < data.size(); i++) {
        if (data[i][ext_index] < val_ext) {
            answer.push_back(data[i]);
        }
    }
    
    sort(answer.begin(), answer.end(), [&](const vector<int>& a, const vector<int>& b) {
        return a[sort_index] < b[sort_index];
    });

    return answer;
}