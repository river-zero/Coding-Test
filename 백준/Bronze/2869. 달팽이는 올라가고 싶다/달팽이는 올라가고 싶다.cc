#include <iostream>
using namespace std;

int main() {
    int A, B, V;
    cin >> A >> B >> V;
    
    int days = (V - B) / (A - B);
    if ((V - B) % (A - B) != 0) {
        days++;
    }
    
    cout << days << endl;
    
    return 0;
}