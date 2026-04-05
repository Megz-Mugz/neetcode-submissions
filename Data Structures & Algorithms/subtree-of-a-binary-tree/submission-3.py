# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], sub_root: Optional[TreeNode]) -> bool:
        
        if not root: return False
        
        if self.isSameTree(root, sub_root):
            return True
        
        return self.isSubtree(root.left, sub_root) or self.isSubtree(root.right, sub_root)
    
    def isSameTree(self, root: Optional[TreeNode], sub_root: Optional[TreeNode]) -> bool:
        
        # leaf nodes, return True
        if not root and not sub_root: return True   
        
        # structure is different
        if (root and not sub_root) or (not root and sub_root): return False

        # values are different
        if root.val != sub_root.val: return False

        # keep recursing
        return self.isSameTree(root.left, sub_root.left) and self.isSameTree(root.right, sub_root.right)