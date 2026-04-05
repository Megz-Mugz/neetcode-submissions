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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (!root) return nullptr;

        // if both are greater, explore right side
        if (p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        // if both are less than, explore left side
        } else if (p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        // if there's a divergence, return the root
        } else {
            return root;
        }

    }
};
