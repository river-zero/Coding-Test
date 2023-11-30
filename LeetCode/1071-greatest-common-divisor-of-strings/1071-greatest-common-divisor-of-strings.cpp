class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() == 0 || str2.size() == 0) return "";
        if (str1 + str2 != str2 + str1) return "";
        
        int n = str1.size();
        int m = str2.size();
        int size = gcd(n, m);
        
        return str1.substr(0, size);
    }
    
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};