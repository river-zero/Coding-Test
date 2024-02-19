#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<tuple<int, int, string>> members;
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        members.push_back(make_tuple(age, i, name));
    }

    sort(members.begin(), members.end());

    for (int i = 0; i < N; i++) {
        cout << get<0>(members[i]) << " " << get<2>(members[i]) << "\n";
    }
}
