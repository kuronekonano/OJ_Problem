class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slow, fast = 0, 0
        while slow < len(nums):
            while slow < len(nums) and nums[slow] != 0:
                slow += 1
            if slow >= len(nums):
                break
            fast = slow
            while fast < len(nums) and nums[fast] == 0:
                fast += 1
            if fast >= len(nums):
                break
            nums[fast], nums[slow] = nums[slow], nums[fast]
