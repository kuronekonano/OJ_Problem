class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        def binsearch(nums):
            l, r = 0, len(nums)
            while l < r:
                mid = (l + r) >> 1
                if nums[mid] <= -1:
                    r = mid
                else:
                    l = mid + 1
            return l
        ans = 0
        for i in grid:
            pos = binsearch(i)
            if pos >= len(i):
                continue
            ans += len(i) - pos
        return ans