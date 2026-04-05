# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        
        ptr = head
        nodes = []
        while (ptr):
            if ptr in nodes:
                return True
            else:
                nodes.append(ptr)
            ptr = ptr.next
        return False