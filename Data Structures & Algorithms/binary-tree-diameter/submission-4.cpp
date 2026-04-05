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
    int diameterOfBinaryTree(TreeNode* root) {
        // NOTE: current node is NOT part of the diameter itself
        int diameter{0};

        dfs(root, diameter);

        return diameter;
    }

private: 
    int dfs(TreeNode* root, int& diameter){
        if (!root) return 0;

        int left = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);

        // calculating diameter is max of left + right
        diameter = std::max(diameter, left + right);
        
        // when you return up to parent, do 1 + max(left + right)
        return 1 + std::max(left, right);

    }

};
