# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head.next == None:
            return head.next
        
        # 1 -> 2 -> 3 -> 4
        length = 0
        curr = head
        
        while curr:
            length += 1
            curr = curr.next

        remove_from_index = length - n
        dummy = ListNode(0, head)

        curr = dummy

        for _ in range(remove_from_index):
            curr = curr.next
        
        # just before node to remove
        curr.next = curr.next.next

        return dummy.next

        






