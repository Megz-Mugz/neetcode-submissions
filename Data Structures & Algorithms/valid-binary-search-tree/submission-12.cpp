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
        return validate_node_ranges(root, -std::numeric_limits<double>::infinity(), 
                                            std::numeric_limits<double>::infinity());
    }

    bool validate_node_ranges(TreeNode* root, double lower_threshold, double upper_threshold){
        if (!root) return true;

        if (root->val <= lower_threshold || root->val >= upper_threshold) return false;

        return validate_node_ranges(root->left, lower_threshold, root->val) && 
                validate_node_ranges(root->right, root->val, upper_threshold);
    }
};
