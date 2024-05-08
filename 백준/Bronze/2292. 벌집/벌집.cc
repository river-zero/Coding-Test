#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 1;
    int num = 1;

    while (num < N) {
        num += 6 * count;
        count++;
    }

    cout << count << endl;

    return 0;
}