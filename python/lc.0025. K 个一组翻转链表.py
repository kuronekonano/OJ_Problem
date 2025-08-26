# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def rev(head, k):
            cnt = 0
            cur = head
            while cur is not None:
                cur = cur.next
                cnt += 1
            if cnt < k:
                return head, None
            cur = head
            pre = None
            for _ in range(k):
                last = cur.next
                cur.next = pre
                pre = cur
                cur = last
            head.next = last
            return pre, head

        fake_head = ListNode(0)
        fake_head.next = head
        cur = head
        pre = fake_head
        while pre.next is not None:
            pre.next, last = rev(cur, k)
            if last is None:
                break
            cur = last.next
            pre = last
        return fake_head.next
            
        
        

        