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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> right_most_nodes{};
        if (!root) return right_most_nodes;

        std::deque<TreeNode*> bfs_deque = {root};

        while (!bfs_deque.empty()){
            int curr_size = bfs_deque.size();
            while (curr_size > 0){
                auto curr_node = bfs_deque.front(); bfs_deque.pop_front();

                if (curr_node->left){
                    bfs_deque.push_back(curr_node->left);
                } 

                if (curr_node->right){
                    bfs_deque.push_back(curr_node->right);
                } 

                if (curr_size == 1){
                    right_most_nodes.push_back(curr_node->val);
                }

                curr_size--;
            }
        }

        return right_most_nodes;

    }
};
