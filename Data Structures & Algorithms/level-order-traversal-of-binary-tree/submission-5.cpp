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
        // check if root is null, if it is, return an empty vector
        if (!root) return {};
        // put root in deque
        std::deque<TreeNode*> level_order_deque = {root};
        std::vector<std::vector<int>> all_levels;
        std::vector<int> current_level;

        while (!level_order_deque.empty()){
            // iterate through the current size of the deque 
            auto level_size = level_order_deque.size();
            
            while (level_size > 0){
                // dequeue the node, adding it to a vector
                auto curr_node = level_order_deque.front(); 
                level_order_deque.pop_front(); // remove it from the deque too

                // check for left & right existence on each iteration, for both left & right add those nodes to deque
                if (curr_node && curr_node->left){
                    level_order_deque.push_back(curr_node->left);
                }

                if (curr_node && curr_node->right){
                    level_order_deque.push_back(curr_node->right);
                }

                current_level.push_back(curr_node->val);

                level_size--;
            }
            
            // after all iteration is done, add the vector to a result's vector
            all_levels.push_back(current_level);
            current_level.clear();

        }
        // return result vector
        return all_levels;
    }
};
