# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        return self.helper(root, float('-inf'), float('inf'))
        
    
    def helper(self, root, lower_threshold, upper_threshold) -> bool:

        # no more nodes to traverse means subtree is valid 
        if not root: return True

        # if node is not in the range, return false
        if root.val <= lower_threshold or root.val >= upper_threshold: return False

        return self.helper(root.left, lower_threshold, root.val) and self.helper(root.right, root.val, upper_threshold)
