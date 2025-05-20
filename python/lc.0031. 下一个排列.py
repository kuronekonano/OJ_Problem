from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 2:
            nums = nums.reverse()
            return
        flag = -1
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                flag = i
                break
        if flag != -1:
            for i in range(len(nums) - 1, flag - 1, -1):
                if nums[i] > nums[flag]:
                    nums[i], nums[flag] = nums[flag], nums[i]
                    break
        l, r = flag + 1, len(nums) - 1
        # print(nums, l, r)
        while l < r:
            if nums[l] > nums[r]:
                nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1


if __name__ == "__main__":
    s = Solution()
    nums = [1, 2, 3]
    s.nextPermutation(nums)
    print(nums)

    nums = [3, 2, 1]
    s.nextPermutation(nums)
    print(nums)

    nums = [1, 1, 5]
    s.nextPermutation(nums)
    print(nums)

    nums = [1, 2]
    s.nextPermutation(nums)
    print(nums)

    nums = [1]
    s.nextPermutation(nums)
    print(nums)

    nums = [1, 3, 2]
    s.nextPermutation(nums)
    print(nums)
