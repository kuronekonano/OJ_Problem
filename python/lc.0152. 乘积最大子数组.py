class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = cur_min = cur_max = nums[0]
        for i in range(1, len(nums)):
            tmp_min = min(nums[i], nums[i] * cur_min, nums[i] * cur_max)
            tmp_max = max(nums[i], nums[i] * cur_min, nums[i] * cur_max) 
            cur_max = tmp_max
            cur_min = tmp_min           
            ans = max(cur_min, cur_max, ans)
        return ans