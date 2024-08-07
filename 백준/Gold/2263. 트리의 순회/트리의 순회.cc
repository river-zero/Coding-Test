#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> inorder, postorder;
unordered_map<int, int> pos;

void findPreorder(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) return;

    int root = postorder[post_end];
    cout << root << ' ';

    int in_root_pos = pos[root];
    int left_size = in_root_pos - in_start;

    findPreorder(in_start, in_root_pos - 1, post_start, post_start + left_size - 1);
    findPreorder(in_root_pos + 1, in_end, post_start + left_size, post_end - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    inorder.resize(n);
    postorder.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    for (int i = 0; i < n; i++) {
        pos[inorder[i]] = i;
    }

    findPreorder(0, n - 1, 0, n - 1);

    return 0;
}
