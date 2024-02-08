#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, less<int>> maxHeap;    // 최대 힙
    priority_queue<int, vector<int>, greater<int>> minHeap; // 최소 힙
    int count = 0;
    
    for (int i = 0; i < operations.size(); i++) {
        // 공백을 기준으로 문자열 파싱
        stringstream ss;
        ss.str(operations[i]);
        string temp;
        ss >> temp;
        
        if (temp == "I") {
            // 해당하는 숫자 큐에 삽입
            ss >> temp;
            int num = stoi(temp);
            maxHeap.push(num);
            minHeap.push(num);
            count++;
        } else if (temp == "D" && count > 0){
            ss >> temp;
            if (temp == "-1") {
                minHeap.pop();
            } else if (temp == "1") {
                maxHeap.pop();
            }
            count--;
            
            if (count == 0){
                while (!maxHeap.empty()){
                    maxHeap.pop();
                }
                while (!minHeap.empty()){
                    minHeap.pop();
                }
            }
        }
    }
    
    // 들어있는 값에 따라서 리턴 결정
    if (count == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(maxHeap.top());
        answer.push_back(minHeap.top());
    }
    
    return answer;
}
