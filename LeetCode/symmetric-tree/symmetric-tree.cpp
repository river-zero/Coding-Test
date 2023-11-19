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
    bool isSymmetric(TreeNode* root) {
        // 트리가 빈 경우 대칭으로 간주
        if (!root) return true;
        
        // 재귀적으로 대칭 여부 확인
        return isSymmetric(root->left, root->right);
    }
    
    bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode) {
        // 양쪽 모두 빈 경우 대칭으로 간주
        if (!leftNode && !rightNode) return true;
        
        // 하나만 빈 경우 대칭 아님
        if (!leftNode || !rightNode) return false;
        
        // 값이 다른 경우 대칭 아님
        if (leftNode->val != rightNode->val) return false;
        
        // 재귀적으로 서브 트리 대칭 여부 확인
        return isSymmetric(leftNode->left, rightNode->right) &&
               isSymmetric(leftNode->right, rightNode->left);
    }
};