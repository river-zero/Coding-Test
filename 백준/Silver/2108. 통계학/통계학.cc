#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers;
    int sum = 0;
    int maxFreq = 0;
    int freq[8001] = {0};

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
        sum += num;
        freq[num + 4000]++;
        maxFreq = max(maxFreq, freq[num + 4000]);
    }

    sort(numbers.begin(), numbers.end());

    vector<int> modes;
    for (int i = 0; i < 8001; i++) {
        if (freq[i] == maxFreq) {
            modes.push_back(i - 4000);
        }
    }

    int mode = modes.size() == 1 ? modes[0] : modes[1];

    double avg = (double)sum / N;
    avg = round(avg);

    cout << (int)avg << '\n';
    cout << numbers[N / 2] << '\n';
    cout << mode << '\n';
    cout << numbers.back() - numbers.front() << '\n';
}