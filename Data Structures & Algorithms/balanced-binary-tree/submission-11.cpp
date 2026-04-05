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
    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;

        dfs(root, is_balanced);

        return is_balanced;
    }

    int dfs(TreeNode* root, bool& is_balanced){
        if (!root) return 0;

        int left = dfs(root->left, is_balanced);
        int right = dfs(root->right, is_balanced);

        if (std::abs(left - right) > 1){
            is_balanced = false;
        }

        return 1 + std::max(left, right);
    }
};
