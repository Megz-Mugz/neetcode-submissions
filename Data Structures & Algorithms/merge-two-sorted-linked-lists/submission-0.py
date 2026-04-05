# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        ptr1 = list1
        ptr2 = list2

        new_list = ListNode()
        new_list_ptr = new_list

        while (ptr1 and ptr2):

            temp1 = ptr1
            temp2 = ptr2

            if (ptr1.val < ptr2.val):
                ptr1 = ptr1.next
                temp1.next = None
                new_list_ptr.next = temp1
                new_list_ptr = new_list_ptr.next
            elif (ptr2.val < ptr1.val):
                ptr2 = ptr2.next
                temp2.next = None
                new_list_ptr.next = temp2
                new_list_ptr = new_list_ptr.next
            else:
                ptr1 = ptr1.next
                ptr2 = ptr2.next
                new_list_ptr.next = temp1
                new_list_ptr = new_list_ptr.next
                new_list_ptr.next = temp2
                new_list_ptr = new_list_ptr.next
        

        if ptr1:
            new_list_ptr.next = ptr1

        if ptr2:
            new_list_ptr.next = ptr2

        return new_list.next
        