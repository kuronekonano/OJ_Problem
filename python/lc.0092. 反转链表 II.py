# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if head is None or left == right:
            return head
        fake_head = ListNode(0, head)
        cnt = 1
        pre = fake_head
        cur = head
        while cur is not None and cnt < left:
            pre = cur
            cur = cur.next
            cnt += 1
        print(pre.val, cur.val)
        
        tmp_pre = pre
        for _ in range(left, right + 1):
            last = cur.next
            cur.next = tmp_pre
            tmp_pre = cur
            cur = last
        tmp = pre.next
        pre.next = tmp_pre
        tmp.next = cur
        return fake_head.next