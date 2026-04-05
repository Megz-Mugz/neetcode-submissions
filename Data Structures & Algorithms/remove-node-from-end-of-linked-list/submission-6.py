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
        # removing a body node is trivial, but a head node is trickier since you don't have something before it
        # using a dummy node gives you that 'something' before it
        # using a dummy node also means you don't need a prev pointer, like what i had before
        dummy = ListNode(0, head)

        curr = dummy
        for _ in range(remove_from_index):
            curr = curr.next
        
        # curr is set to just before node to remove, 
        # so you can 'jump' over it
        curr.next = curr.next.next

        return dummy.next

        






