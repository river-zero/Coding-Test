#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, string> password;

    for (int i = 0; i < N; i++) {
        string site, pw;
        cin >> site >> pw;
        password[site] = pw;
    }

    for (int i = 0; i < M; i++) {
        string site;
        cin >> site;
        cout << password[site] << '\n';
    }

    return 0;
}