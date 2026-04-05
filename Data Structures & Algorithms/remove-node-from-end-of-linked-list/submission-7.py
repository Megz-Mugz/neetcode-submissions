# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head.next == None:
            return None
        
        # step 1. count the number of nodes
        length = 0
        curr = head
        while curr:
            length += 1
            curr = curr.next

        # calculate the index that you need to remove 
        remove_from_index = length - n
        
        prev, curr = None, head

        for i in range(remove_from_index):
            prev = curr
            curr = curr.next
        
        # if your removing head, handle separately
        if curr == head:
            return head.next
        else:
            prev.next = curr.next
            return head
        

        






