# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head.next is None:
            return
        def check(node):
            if node.next is None:
                return False
            if node.next.next is None:
                return False
            return True

        def rev(node):
            if node.next is None:
                return node
            cur = node
            pre = None
            while cur is not None:
                nxt = cur.next
                cur.next = pre
                pre = cur 
                cur = nxt
            return pre

        
        lhalf = head
        slow = head
        fast = head
        while check(fast):
            slow = slow.next
            fast = fast.next.next
        rhalf = rev(slow.next)
        slow.next = None

        lcur = lhalf
        rcur = rhalf
        while rcur is not None:
            tmp = lcur.next
            lcur.next= rcur
            lcur = tmp
            tmp = rcur.next
            rcur.next = lcur
            rcur = tmp 
