/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, INT_MIN);
    }

private:
    int goodNodes(TreeNode* root, int maxVal) {
        if (!root) {
            return 0;
        }
        
        int count = (root->val >= maxVal) ? 1 : 0;
        
        count += goodNodes(root->left, max(root->val, maxVal));
        count += goodNodes(root->right, max(root->val, maxVal));
        
        return count;
    }
};