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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidBST(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) {
            return true;
        }
        
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        
        return isValidBST(node->left, minVal, node->val) && isValidBST(node->right, node->val, maxVal);
    }
};