from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def create_list(self, arr):
        if not arr:
            return None
        head = ListNode(arr[0])
        cur = head
        for i in arr[1:]:
            cur.next = ListNode(i)
            cur = cur.next
        self.print(head)
        return head

    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        pre = ListNode(0)
        pre.next = head
        cur = pre.next
        last = pre
        while cur:
            c_nxt = cur.next
            if not c_nxt:
                break
            last.next = c_nxt
            last = cur
            cur.next = c_nxt.next
            c_nxt.next = cur
            cur = cur.next
        # self.print(pre.next)
        return pre.next

    def print(self, head: Optional[ListNode]):
        print("=", end="")
        if not head:
            return
        cur = head
        while cur:
            print(cur.val, end=" ")
            cur = cur.next
        print()


if __name__ == "__main__":
    s = Solution()
    h = s.create_list([1, 2, 3, 4])
    s.swapPairs(h)
    h = s.create_list([])
    s.swapPairs(h)
    h = s.create_list([1])
    s.swapPairs(h)
    h = s.create_list([1, 2, 3])
    s.swapPairs(h)
