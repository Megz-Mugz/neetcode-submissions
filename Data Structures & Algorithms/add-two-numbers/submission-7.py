# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        num_1 = ""
        while l1:
            num_1 += str(l1.val)
            l1 = l1.next

        num_2 = ""
        while l2:
            num_2 += str(l2.val)
            l2 = l2.next
        
        answer = str(int(num_1[::-1]) + int(num_2[::-1]))[::-1]
        dummy = ListNode()
        curr = dummy
        for i in range(len(answer)):
            curr.next = ListNode(int(answer[i]))
            curr = curr.next


        return dummy.next