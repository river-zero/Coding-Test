#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int int_result = A + B - C;
    cout << int_result << endl;

    string strA = to_string(A);
    string strB = to_string(B);
    string strC = to_string(C);

    string str_concat = strA + strB; 
    int str_result = stoi(str_concat) - stoi(strC);
    cout << str_result << endl;

    return 0;
}
