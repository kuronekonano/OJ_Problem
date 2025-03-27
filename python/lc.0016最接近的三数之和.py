from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = sum(nums[:3])
        for i in range(len(nums) - 2):
            l, r = i + 1, len(nums) - 1
            if nums[i] == nums[i - 1]:
                continue
            while l < r:
                if abs(ans - target) > abs((nums[i] + nums[l] + nums[r]) - target):
                    ans = nums[i] + nums[l] + nums[r]
                if nums[i] + nums[l] + nums[r] > target:
                    r -= 1
                    while nums[r] == nums[r + 1] and l < r:
                        r -= 1
                elif nums[i] + nums[l] + nums[r] < target:
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                else:
                    return target
        return ans


if __name__ == "__main__":
    s = Solution()
    print(s.threeSumClosest([-1, 2, 1, -4], 2))
    print(s.threeSumClosest([0, 0, 0], 0))
    print(s.threeSumClosest([-10000, 1, 3, 10000], 3))
