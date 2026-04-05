# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        level_order = []

        storage = deque([root])

        while storage:
            level_length = len(storage)
            level = []
            for i in range(level_length):
                node = storage.popleft()
                if node:
                    level.append(node.val)
                    storage.append(node.left)
                    storage.append(node.right)
            
            if level:
                level_order.append(level)
        
        return level_order
