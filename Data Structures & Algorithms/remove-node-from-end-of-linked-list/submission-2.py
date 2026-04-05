# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        
        ptr = head
        total = 0
        while ptr:
            ptr = ptr.next
            total += 1
        
        if total - n == 0:
            return head.next

        cur = head
        block = 0

        while cur:
            if (block + 1 == total - n):
                cur.next = cur.next.next
                break
            cur = cur.next
            block += 1
        return head
        
        