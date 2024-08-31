#include <iostream>
using namespace std;

void printFizzBuzz(int number) {
    if (number % 3 == 0 && number % 5 == 0) {
        cout << "FizzBuzz";
    } else if (number % 3 == 0) {
        cout << "Fizz";
    } else if (number % 5 == 0) {
        cout << "Buzz";
    } else {
        cout << number;
    }
}

bool tryFizzBuzz(const string& str, int increment) {
    if (isdigit(str[0]) || (str[0] == '-' && isdigit(str[1]))) {
        int number = stoi(str) + increment;
        printFizzBuzz(number);
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b, c;
    cin >> a >> b >> c;

    if (!tryFizzBuzz(c, 1) && !tryFizzBuzz(b, 2)) {
        tryFizzBuzz(a, 3);
    }

    return 0;
}
