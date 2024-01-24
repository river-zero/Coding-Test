/*
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    int temp;
    vector<int> num;
    
    // stringstream에 문자열 s를 넣고
    // 숫자를 하나씩 읽어서 벡터에 넣음
    stringstream ss(s);
    while (ss >> temp) {
        num.push_back(temp);
    }
    
    pair minmax = std::minmax_element(num.begin(), num.end());
    return std::to_string(*minmax.first) + " " + std::to_string(*minmax.second);
}
*/

#include <string>
#include <algorithm>

std::string solution(std::string s) {
    std::string buffer;
    std::vector<int> numbers;
    
    // 마지막 수까지 처리할 수 있도록 공백 추가
    s.push_back(' ');
    
    for (char n : s) {
        // 공백이라면 해당 숫자를 푸쉬
        if(n == ' ') {
            if(!buffer.empty()) {
                numbers.push_back(stoi(buffer));
                buffer.clear(); 
            }
        // 공백이 아니라면 buffer에 숫자 할당
        } else {
            buffer += n;
        }
    }
    
    auto minmax = std::minmax_element(numbers.begin(), numbers.end());
    return std::to_string(*minmax.first) + " " + std::to_string(*minmax.second);
}