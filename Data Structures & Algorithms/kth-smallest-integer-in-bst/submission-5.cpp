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
    int kthSmallest(TreeNode* root, int k) {
        /* 
        - in order traversal will give us the integers in ascending order
        - once the num of processed nodes == k, return it's val
        */
        std::vector<int> vals;
        in_order_traversal(root, vals);
        return vals[k-1];
    }
    
    void in_order_traversal(TreeNode* root, std::vector<int>& vals){
        if (!root) return;

        in_order_traversal(root->left, vals);
        vals.push_back(root->val);
        in_order_traversal(root->right, vals);
    }

};
