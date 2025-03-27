from collections import defaultdict
from bisect import bisect_left, bisect_right

class RangeFreqQuery:

    def __init__(self, arr):
        self.count = defaultdict(list)
        for idx, i in enumerate(arr):
            self.count[i].append(idx)

    def bisect(self, arr, value):
        l, r = 0, len(arr) - 1
        while l < r:
            mid = (l + r) >> 1
            if arr[mid] == value:
                return mid
            elif arr[mid] > value:
                r = mid - 1
            else:
                l = mid + 1
        return l

    def query(self, left, right, value):
        if len(self.count[value]) == 0:
            return 0
        start = self.bisect(self.count[value], left)
        if self.count[value][start] < left:
            start += 1
        end = self.bisect(self.count[value], right)
        if self.count[value][end] <= right:
            end += 1
        return end - start

    def or_query(self, left, right, value):
        a = self.pos[value]
        return bisect_right(a, right) - bisect_left(a, left)


# Your RangeFreqQuery object will be instantiated and called as such:
# obj = RangeFreqQuery(arr)
# param_1 = obj.query(left,right,value)
