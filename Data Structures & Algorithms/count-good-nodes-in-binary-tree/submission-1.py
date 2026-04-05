# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        # if curr_node_val > max_node_val: count += 1
        good_nodes_count = 0
        def dfs(root, max_value):
            nonlocal good_nodes_count

            if not root: return

            if root.val >= max_value:
                good_nodes_count += 1
                dfs(root.left, root.val)
                dfs(root.right, root.val)
            else:
                dfs(root.left, max_value)
                dfs(root.right, max_value)
                

        dfs(root, float('-inf'))
        return good_nodes_count