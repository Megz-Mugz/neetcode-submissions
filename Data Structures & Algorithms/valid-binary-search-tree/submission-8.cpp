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
        return validateBST(root, LONG_MIN, LONG_MAX);
    }

    bool validateBST(TreeNode* root, long min_allowed, long max_allowed){
        if (!root) return true;

        if (root->val <= min_allowed || root->val >= max_allowed) return false;
        std::cout << "min: " << min_allowed << " Root: " << root->val << " max: " << max_allowed << std::endl;

        return validateBST(root->left, min_allowed, root->val) && validateBST(root->right, root->val, max_allowed);
    }
};
