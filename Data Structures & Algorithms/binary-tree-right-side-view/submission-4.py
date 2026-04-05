# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
        right_side_nodes = [] # stores right most nodes' values
        if root is None: return right_side_nodes # guard rail for when tree has 0 nodes

        nodes = deque([root]) # start bfs with something in there

        while nodes:

            len_of_level = len(nodes)

            for i in range(len_of_level):
                
                node = nodes.popleft()

                if i == len_of_level - 1: # last thing in the deque
                    right_side_nodes.append(node.val)
                
                if node.left:
                    nodes.append(node.left)
                if node.right:    
                    nodes.append(node.right)
        
        return right_side_nodes
