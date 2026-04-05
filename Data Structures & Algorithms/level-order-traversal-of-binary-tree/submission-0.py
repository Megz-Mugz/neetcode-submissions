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

        q = deque([(root, 0)])

        while q:
            print(q)
            node, level = q.popleft()  

            if len(resulting_arr) <= level:
                resulting_arr.append([])

            resulting_arr[level].append(node.val)

            if node.left:
                q.append((node.left, level + 1))
            if node.right:
                q.append((node.right, level + 1))

        return resulting_arr



        