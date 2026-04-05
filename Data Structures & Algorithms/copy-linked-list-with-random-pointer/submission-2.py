"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':

        connections = {} # key_node -> [next_node, random_node]
        curr = head

        while curr:
            connections[curr] = Node(curr.val)
            curr = curr.next
        
        curr = head
        while curr:
            connections[curr].next = connections.get(curr.next, None)
            connections[curr].random = connections.get(curr.random, None)
            curr = curr.next
        
        return connections[head] if head else None

        