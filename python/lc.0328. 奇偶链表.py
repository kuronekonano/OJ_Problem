# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cnt = 0
        even_head = ListNode(0)
        even = even_head
        odd_head = ListNode(0)
        odd = odd_head
        cur = head
        while cur is not None:
            cnt += 1
            if cnt % 2 != 0:
                odd.next = cur
                odd = odd.next
            else:
                even.next = cur
                even = even.next
            cur = cur.next
        odd.next = even.next = None

        odd.next = even_head.next
        return odd_head.next
            