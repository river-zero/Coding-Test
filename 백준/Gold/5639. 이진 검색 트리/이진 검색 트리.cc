#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    void postOrderTraversal() {
        postOrderRec(root);
        cout << '\n';
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void postOrderRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        postOrderRec(node->left);
        postOrderRec(node->right);
        cout << node->value << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BinaryTree tree;
    int value;

    while (cin >> value) {
        tree.insert(value);
    }

    tree.postOrderTraversal();

    return 0;
}
