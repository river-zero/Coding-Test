#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M;
    cin >> M;

    int S = 0;
    string command;
    int num;

    while (M--) {
        cin >> command;

        if (command == "add") {
            cin >> num;
            S |= (1 << num);
        } else if (command == "remove") {
            cin >> num;
            S &= ~(1 << num);
        } else if (command == "check") {
            cin >> num;
            if (S & (1 << num)) cout << "1\n";
            else cout << "0\n";
        } else if (command == "toggle") {
            cin >> num;
            S ^= (1 << num);
        } else if (command == "all") {
            S = (1 << 21) - 1;
        } else if (command == "empty") {
            S = 0;
        }
    }
}
