"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None

        # solving using bfs
        queue = deque([node])
        old_to_new = {} # acts as "visited" in a conventional BFS

        while queue:
            curr_node = queue.popleft()

            if curr_node not in old_to_new:
                old_to_new[curr_node] = Node(curr_node.val)

            print([neighbor.val for neighbor in curr_node.neighbors])

            for neighbor in curr_node.neighbors: # neighbor is from the original graph
                if neighbor not in old_to_new: 
                    queue.append(neighbor) # only enqueue neighbor if NOT already visited
                    old_to_new[neighbor] = Node(neighbor.val) # create said entry
                    
                old_to_new[curr_node].neighbors.append(old_to_new[neighbor]) # add the new neighbor to the copy's list of neighbors
                    
        return old_to_new[node]

        
            