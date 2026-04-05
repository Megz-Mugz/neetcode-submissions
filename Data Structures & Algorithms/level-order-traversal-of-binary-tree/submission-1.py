# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        resulting_arr = []

        if root is None:
            return resulting_arr

        q = deque([(root)])
        level_arr = []
        while q:
            size_of_level = len(q)
            level_arr = []

            for _ in range(size_of_level):
                node = q.popleft()
                level_arr.append(node.val)
            
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            
            resulting_arr.append(level_arr)

        return resulting_arr



        