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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 결과를 저장할 2차원 벡터
        std::vector<std::vector<int>> result;
        
        // 빈 경우 바로 반환
        if (!root) return result;
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            // 현재 레벨에 있는 노드 수
            int level = q.size();
            
            // 현재 레벨의 노드 값을 저장할 벡터
            std::vector<int> value;
            
            for (int i = 0; i < level; i++) {
                // 큐에서 노드를 꺼내 현재 레벨 벡터에 추가
                TreeNode* node = q.front();
                q.pop();
                value.push_back(node->val);
                
                // 왼쪽 자식 노드가 있다면 추가
                if (node->left) {
                    q.push(node->left);
                }
                
                // 오른쪽 자식 노드가 있다면 추가
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            // 현재 레벨의 노드 벡터를 결과에 추가
            result.push_back(value);
        }
        
        return result;
    }
};