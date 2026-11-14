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

        // If no root node, return an empty vector
        if (!root) return {};

        std::deque<TreeNode*> to_process = {root};
        std::vector<std::vector<int>> level_order;

        // Keep processing as long as we have items to process
        while (to_process.size() > 0){
            std::vector<int> processed_nodes; 

            // Check size of current level
            size_t current_level_size = to_process.size();

            // Process all the nodes at this level
            for (int i{}; i < current_level_size; i++){ 
                // Reveal & pop the left-most node
                auto curr_node = to_process.front(); 
                to_process.pop_front();

                // Check the current node's left & right children, mark them as to be processed
                if (curr_node->left)
                    to_process.push_back(curr_node->left);

                if (curr_node->right)
                    to_process.push_back(curr_node->right);

                // Finished processing the current node, add it to processed nodes vector
                processed_nodes.push_back(curr_node->val);
            }

            // Add all of the processed nodes for the most recent level to another vector to return
            level_order.push_back(processed_nodes);
        }

        // Return an organized vector of vectors containing each node in level order traversal
        return level_order;
    }
};
