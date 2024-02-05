#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums) {
    int num = nums.size() / 2;
    set<int> s(nums.begin(), nums.end());
    
    if (num < s.size()) return num;
    else return s.size();
}