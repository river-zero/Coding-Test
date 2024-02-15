#include <iostream>

using namespace std;

int main() {
    int input;
    int index = 0;
    int max = -1;
    
    for (int i = 0; i < 9; i++) {
        cin >> input;
        
        if (input > max) {
            max = input;
            index = i + 1;
        }
    }
    
    cout << max << endl << index;
}