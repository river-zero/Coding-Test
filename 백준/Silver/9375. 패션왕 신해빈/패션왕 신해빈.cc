#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        map<string, int> clothes;

        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            clothes[type]++;
        }

        int result = 1;

        for (auto it = clothes.begin(); it != clothes.end(); it++) {
            result *= (it->second + 1);
        }

        result--;

        cout << result << '\n';
    }

    return 0;
}