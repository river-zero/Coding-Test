#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int t = bandage[0];      // 기술 시전 시간
    int x = bandage[1];      // 초당 회복량
    int y = bandage[2];      // 추가 회복량
    int sucessTime = 0;      // 연속 성공 시간
    int currHealth = health; // 현재 체력
    int currTime = 1;        // 현재 시간
    
    for (const auto attack : attacks) {
        int attackTime = attack[0]; // 공격 시간
        int damage = attack[1];     // 피해량
        
        while (currTime < attackTime) {
            currHealth += x;
            currTime++;
            sucessTime++;
            
            // 연속 성공이라면 추가 회복
            if (sucessTime == t) {
                currHealth += y;
                sucessTime = 0;
            }
                
            // 최대 체력을 초과하지 않도록 체크
            if (currHealth > health) {
                currHealth = health;
            }
        }
        
        // 공격 시간이 되었으므로 피해 입음
        currHealth -= damage;
        sucessTime = 0;
        currTime++;
        
        // 체력이 0 이하라면 -1 반환
        if (currHealth <= 0) return -1;
    }
    
    return currHealth;
}