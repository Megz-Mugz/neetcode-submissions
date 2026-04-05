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
        return count_good_nodes(root, root->val);
    }


    int count_good_nodes(TreeNode* root, int curr_max){
        if (!root) return 0;

        auto res = (root->val >= curr_max ? 1 : 0);
        curr_max = std::max(curr_max, root->val);
        res += count_good_nodes(root->left, curr_max);
        res += count_good_nodes(root->right, curr_max);
        
        return res;

    }
};
