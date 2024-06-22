#include <iostream>
using namespace std;

struct Node {
    char left, right;
};

Node tree[26];

void preorder(char root) {
    if (root == '.') return;
    cout << root;
    preorder(tree[root - 'A'].left);
    preorder(tree[root - 'A'].right);
}

void inorder(char root) {
    if (root == '.') return;
    inorder(tree[root - 'A'].left);
    cout << root;
    inorder(tree[root - 'A'].right);
}

void postorder(char root) {
    if (root == '.') return;
    postorder(tree[root - 'A'].left);
    postorder(tree[root - 'A'].right);
    cout << root;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root - 'A'].left = left;
        tree[root - 'A'].right = right;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
}
