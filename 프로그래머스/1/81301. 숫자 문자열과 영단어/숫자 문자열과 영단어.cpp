/*
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");    
    return stoi(s);
}
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = "";
    vector<string> arr = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (auto c : s) {
        if (isdigit(c)) answer = answer * 10 + c - '0';
        // 단일 문자를 처리할 때 c - '0'을 사용
        // stoi는 문자열 전체를 처리하는 데 더 적합
        else temp.push_back(c);
        
        for (int i = 0; i <= 9; i++) {
            if (arr[i] == temp) {
                answer = answer * 10 + i;
                temp = "";
                break;
            }
        }
    }
    
    return answer;
}