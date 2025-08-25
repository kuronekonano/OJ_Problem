class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        sum = [0 for _ in range(len(nums) + 1)]
        sum[0] = 0
        for i in range(1, len(nums) + 1):
            sum[i] = nums[i - 1] + sum[i - 1]
        ans = len(nums) + 1
        q = []
        for i, v in enumerate(sum):
            if q:
                print(v - sum[q[0]])
            while q and v - sum[q[0]] >= k:
                ans = min(ans, i - q.pop(0))
            while q and sum[q[-1]] >= v:  # 因为大于等于 k 即可，所以用单调栈存递增的序列和即可
                q.pop()
            q.append(i)
        return ans if ans <= len(nums) else -1
