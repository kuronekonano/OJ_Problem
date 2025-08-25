class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        a = [0] * 10001
        mx = 0
        for i in nums:
            a[i] += i
            mx = max(i, mx)
        for i in range(2, mx+1):
            a[i] = max(a[i-2] + a[i], a[i-1])
        return a[mx]