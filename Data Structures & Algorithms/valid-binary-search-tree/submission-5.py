# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        

        def valid(root, min_allowed, max_allowed) -> bool:

            if not root: return True

            if not (min_allowed < root.val < max_allowed): return False

            return valid(root.left, min_allowed, root.val) and valid(root.right, root.val, max_allowed)

        return valid(root, float("-inf"), float("inf"))
