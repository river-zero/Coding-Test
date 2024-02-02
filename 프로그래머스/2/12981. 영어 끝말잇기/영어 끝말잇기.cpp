#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    map<string, int> m;
    m[words[0]]++;

    for (int i = 1; i < words.size(); i++) {
        // 만약 이미 나온 단어거나 규칙에 어긋나면 리턴
        if (m[words[i]] > 0 || words[i].front() != words[i - 1].back()) {
            return {(i % n) + 1, (i / n) + 1};
        }

        m[words[i]]++;
    }

    return {0, 0};
}