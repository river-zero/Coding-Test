#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    
    for (int i = 0; i < cities.size(); i++) {
        string city = cities[i];
        
        // 소문자로 변환
        for (int j = 0; j < city.size(); j++) {
            city[j] = tolower(city[j]);
        }
        
        bool hit = false;
        int index = 0;
        
        // 캐시가 hit인지 miss인지 판단
        for (index = 0; index < cache.size(); index++) {
            if (cache[index] == city) {
                hit = true;
                break;
            }
        }
        
        cache.push_back(city);
        
        // hit인 경우
        if (hit) {
            cache.erase(cache.begin() + index);
            answer += 1;
        }
        
        // miss인 경우
        else {
            if (cache.size() > cacheSize) {
                cache.pop_front();
            }
            answer += 5;
        }
    }
    
    return answer;
}