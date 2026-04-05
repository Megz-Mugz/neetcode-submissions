# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        merged_linked_list = ListNode()
        merged_ptr = merged_linked_list

        while list1 and list2:

            if list1.val <= list2.val:
                merged_ptr.next = list1
                list1 = list1.next
            else:
                merged_ptr.next = list2
                list2 = list2.next

            merged_ptr = merged_ptr.next
        
        merged_ptr.next = list1 if list2 is None else list2
        return merged_linked_list.next