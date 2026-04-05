# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # MUST BE DONE IN PLACE

        # using slow & fast ptr approach, split LL in the middle
        slow, fast = head, head
        while (fast and fast.next):
            slow = slow.next
            fast = fast.next.next

        # reverse linked list w/ prev = None, and curr = slow from step above
        prev, curr = None, slow
        while (curr):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        # connect LL in interweaving fashion
        left, right = head, prev
        while (left != right):
            temp_left = left.next
            if right: temp_right = right.next

            left.next = right
            if right:
                right.next = temp_left

            left = temp_left
            right = temp_right