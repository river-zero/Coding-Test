/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 노드가 비었거나 찾은 경우
        if (!root || root == p || root == q) {
            return root;
        }
        
        // 좌측 서브트리에서 LCA 탐색
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        
        // 우측 서브트리에서 LCA 탐색
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
        
        // 우측과 좌측 결과를 통합해 최종 LCA 반환
        if (leftLCA && rightLCA) {
            return root;
        }
        
        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }
};