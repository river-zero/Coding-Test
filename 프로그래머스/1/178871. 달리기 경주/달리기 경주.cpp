#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    int n = players.size();
    unordered_map<string, int> playerAndRank;
    unordered_map<int, string> rankAndPlayer;
    
    // 초기값 설정
    for (int i = 0; i < n; i++) {
        playerAndRank[players[i]] = i + 1;
        rankAndPlayer[i + 1] = players[i];
    } 

    for (const string& call : callings) {
        int rank = playerAndRank[call];
        
        if (rank > 1) {
            // 등수 변경
            swap(rankAndPlayer[rank], rankAndPlayer[rank - 1]);
            
            // 등수 업데이트
            playerAndRank[rankAndPlayer[rank]] = rank;
            playerAndRank[rankAndPlayer[rank - 1]] = rank - 1;
        }
    }
    
    vector<string> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = rankAndPlayer[i + 1];
    }
    return result;
}