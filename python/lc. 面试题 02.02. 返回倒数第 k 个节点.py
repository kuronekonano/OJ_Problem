# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def kthToLast(self, head: Optional[ListNode], k: int) -> int:
        cnt = 0
        cur = head
        while cur is not None:
            cnt += 1
            cur = cur.next
        target = cnt - k
        cnt = 0
        cur = head
        while cnt < target:
            cnt += 1
            cur = cur.next
        return cur.val