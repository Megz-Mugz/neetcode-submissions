# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        
        if (not root1 and not root2):
            return True
        elif (root1 and root2 and root1.val == root2.val):
            return self.isSameTree(root1.left, root2.left) and self.isSameTree(root1.right, root2.right)
        else:
            return False