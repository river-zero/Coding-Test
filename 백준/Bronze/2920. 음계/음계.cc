#include <iostream>

using namespace std;

int main() {
    int arr[8];
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    string result = "";
    for (int i = 0; i < 7; i++) {
        if (arr[i] < arr[i+1]) {
            if (result == "" || result == "ascending") {
                result = "ascending";
            } else {
                result = "mixed";
                break;
            }
        } else if (arr[i] > arr[i + 1]) {
            if (result == "" || result == "descending") {
                result = "descending";
            } else {
                result = "mixed";
                break;
            }
        }
    }

    cout << result << endl;
}
