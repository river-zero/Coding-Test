#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> remainders(42, false); 
    int count = 0;

    for (int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        int remainder = num % 42;
        
        if (!remainders[remainder]) { 
            remainders[remainder] = true;
            count++;
        }
    }

    cout << count << endl;
}