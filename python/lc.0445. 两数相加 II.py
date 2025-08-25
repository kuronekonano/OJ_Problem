# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def buid_num_from_link(cur, num):
            if cur is None:
                return num
            return buid_num_from_link(cur.next, num * 10 + cur.val)
            
        def build_link_from_num(num):
            if num // 10 == 0:
                first = ListNode(num)
                return first, first
            first, last = build_link_from_num(num // 10)
            last.next = ListNode(num % 10)
            return first, last.next
        
        a1 = 0 if l1.val == 0 else buid_num_from_link(l1, 0)
        a2 = 0 if l2.val == 0 else buid_num_from_link(l2, 0)
        return build_link_from_num(a1+a2)[0]


        