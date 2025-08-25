class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sums = [nums[0]]
        check = {sums[0] - nums[0]: 1}
        ans = 1 if nums[0] == k else 0
        for i in range(1, len(nums)):
            sums.append(nums[i] + sums[-1])
            
            if sums[i] - nums[i] not in check:
                check[sums[i] - nums[i]] = 0
            check[sums[i] - nums[i]] += 1
            ans += check.get(sums[i] - k, 0)
        return ans