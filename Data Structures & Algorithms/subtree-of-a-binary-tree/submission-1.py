# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], sub_root: Optional[TreeNode]) -> bool:
        
        if not subRoot: return True
        if not root: return False

        # sort of a brute force approach, you check every single possible node 
        # that is connected to the root and see if it overlaps with anything in sub_root
        # the actual code for same_tree is trivial
        if self.same_tree(root, subRoot): return True

        return (self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot))
    
    
    def same_tree(self, root: Optional[TreeNode], sub_root: Optional[TreeNode]) -> bool:

        if not root and not sub_root:
            return True
        
        if (root and not sub_root) or (not root and sub_root):
            return False
        
        if root.val != sub_root.val:
            return False
        
        return self.same_tree(root.left, sub_root.left) and self.same_tree(root.right, sub_root.right)
        
