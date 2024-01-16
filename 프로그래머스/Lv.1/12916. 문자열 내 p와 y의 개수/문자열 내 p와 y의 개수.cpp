#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    int pCount = count(s.begin(), s.end(), 'p');
    int yCount = count(s.begin(), s.end(), 'y'); 
    
    return pCount == yCount;
}