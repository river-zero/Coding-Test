class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;
        
        // 입력 문자열을 스트림으로 읽어와 단어 단위로 저장
        while (iss >> word) {
            words.push_back(word);
        }
        
        // 원래 문자열을 초기화하고 역순으로 저장
        s = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            s += words[i];
            if (i > 0) {
                s += " ";
            }
        }
        
        return s;
    }
};