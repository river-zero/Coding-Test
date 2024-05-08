#include <iostream>
using namespace std;

int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    int result = 0;
    for (int i = 1; i < N; i++) {
        int digitSum = getDigitSum(i);
        if (i + digitSum == N) {
            result = i;
            break;
        }
    }

    cout << result << endl;

    return 0;
}