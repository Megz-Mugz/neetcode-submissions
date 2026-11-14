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
        /* 
            1. add root to a deque
            2. start by checking how many nodes are at current level
            3. process the nodes at current level
                - pop the leftmost node in deque to process
                - check the popped node's left & right child
                    - add these children to the deque to process
            4. finished processing node, add the processed node to a processed vector
            5. add the processed vector to another vector containing all teh levels
        */

        if (!root) return {};

        std::deque<TreeNode*> to_process = {root};
        std::vector<std::vector<int>> level_order;

        while (to_process.size() > 0){
            std::vector<int> processed_nodes; 

            size_t current_level_size = to_process.size();

            for (int i{}; i < current_level_size; i++){ 
                auto curr_node = to_process.front(); 
                to_process.pop_front();

                if (curr_node->left)
                    to_process.push_back(curr_node->left);

                if (curr_node->right)
                    to_process.push_back(curr_node->right);

                processed_nodes.push_back(curr_node->val);
            }

            level_order.push_back(processed_nodes);
        }
        return level_order;
    }
};
