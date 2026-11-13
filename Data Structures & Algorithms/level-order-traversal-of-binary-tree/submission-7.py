# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # implement a breadth first search

        '''
            1. add root to "to_process" queue
            2. start at root, check left & right neighbors
            3. add left and right neighbors to a "to_process" queue
            3.5 add nodes to a level_order = []
            4. repeat steps 2-3 until "to_process" is empty
        '''
        # Guard clause
        if not root: return []

        level_order = []
        to_process = deque([root])

        while to_process:

            # Process all the nodes at the current level
            current_level_size = len(to_process)

            current_level = []

            for _ in range(current_level_size):
                # print(f'To Process {[node.val for node in to_process]}')
                curr_node = to_process.popleft()

                # Check if the current node has children nodes
                if (curr_node.left):
                    # print(f'{curr_node.val} has a left child of {curr_node.left.val}')
                    to_process.append(curr_node.left)
                if (curr_node.right):
                    # print(f'{curr_node.val} has a right child of {curr_node.right.val}')
                    to_process.append(curr_node.right)
            
                current_level.append(curr_node.val)
            
            # Add all the nodes from current level to the final array
            level_order.append(current_level)

        return level_order
            
        