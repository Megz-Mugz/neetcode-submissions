# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        curr_ptr1, curr_ptr2  = l1, l2
        l1_sum, l2_sum  = 0, 0
        i1, i2 = 1, 1
        head = ListNode
        final_ptr = head
        digit_count = 1

        while curr_ptr1:
            l1_sum += (curr_ptr1.val * i1)
            i1 *= 10
            curr_ptr1 = curr_ptr1.next
        while curr_ptr2:
            l2_sum += (curr_ptr2.val * i2)
            i2 *= 10
            curr_ptr2 = curr_ptr2.next

        total_sum = l1_sum + l2_sum
        count = len(str(total_sum))

        while digit_count <= count:
            new_val = total_sum % 10
            total_sum //= 10
            final_ptr.next = ListNode(new_val, None)
            final_ptr = final_ptr.next
            digit_count += 1
        return head.next
