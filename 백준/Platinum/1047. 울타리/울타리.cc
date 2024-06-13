#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = n;

    vector<int> x(n), y(n), fenceCost(n);
    vector<int> xSorted(x), ySorted(y);

    // 입력 받기
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> fenceCost[i];
        xSorted[i] = x[i];
        ySorted[i] = y[i];
    }

    sort(xSorted.begin(), xSorted.end());
    sort(ySorted.begin(), ySorted.end());

    for (int a = 0; a < n; a++) {
        for (int b = a; b < n; b++) {
            for (int c = 0; c < n; c++) {
                for (int d = c; d < n; d++) {
                    int ntree = 0, outSum = 0, inSum = 0;
                    int need = 2 * (xSorted[b] - xSorted[a] + ySorted[d] - ySorted[c]);
                    vector<int> inFenceCost;

                    for (int i = 0; i < n; i++) {
                        if (x[i] >= xSorted[a] && x[i] <= xSorted[b] && y[i] >= ySorted[c] && y[i] <= ySorted[d]) {
                            ntree++;
                            inFenceCost.push_back(fenceCost[i]);
                            inSum += fenceCost[i];
                        } else {
                            outSum += fenceCost[i];
                        }
                    }

                    if (outSum >= need) {
                        res = min(res, n - ntree);
                    } else {
                        if (outSum + inSum >= need) {
                            sort(inFenceCost.begin(), inFenceCost.end(), greater<int>());
                            for (int i = 0; i < inFenceCost.size(); i++) {
                                ntree--;
                                outSum += inFenceCost[i];
                                if (outSum >= need) {
                                    res = min(res, n - ntree);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}