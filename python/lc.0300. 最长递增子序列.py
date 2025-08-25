class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        ans = []
        def binsearch(_nums, target):
            l, r = 0, len(_nums)
            while l < r:
                mid = (l + r) >> 1
                if _nums[mid] >= target:
                    r = mid
                else:
                    l = mid + 1
            return l
        flagmax = 1
        ans.append(nums[0])
        for i in nums[1:]:
            if i > ans[-1]:
                ans.append(i)
            else:
                pos = binsearch(ans, i)
                ans[pos] = i
        return len(ans)