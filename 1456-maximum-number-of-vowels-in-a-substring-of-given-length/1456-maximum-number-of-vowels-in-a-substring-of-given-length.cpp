class Solution {
public:
    int maxVowels(std::string s, int k) {
        int n = s.size();
        int maxVowelCount = 0;
        int currentVowelCount = 0;

        // 초기 부분 문자열의 모음 개수 설정
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                currentVowelCount++;
            }
        }
        maxVowelCount = currentVowelCount;

        // 부분 문자열을 한 칸씩 오른쪽으로 이동하면서 최대 모음 개수를 갱신
        for (int i = k; i < n; i++) {
            if (isVowel(s[i - k])) {
                currentVowelCount--;
            }
            if (isVowel(s[i])) {
                currentVowelCount++;
            }

            maxVowelCount = std::max(maxVowelCount, currentVowelCount);
        }

        return maxVowelCount;
    }

private:
    // 주어진 문자가 모음인지 확인하는 함수
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};