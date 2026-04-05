# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            # prev after temp
        # 2 -> 4  6 -> 8
        after = slow.next
        slow.next = None
        prev = None
        # reverse the
        while after:
            temp = after.next
            after.next = prev
            prev = after
            after = temp
        
        first, second = head, prev

        while second:
            temp1, temp2 = first.next, second.next
            first.next = second
            second.next = temp1
            first, second = temp1, temp2
            
