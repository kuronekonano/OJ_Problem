class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 1:
            return 0 if nums[0] == target else -1
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l+r) >> 1
            if nums[mid] == target:
                return mid
            if nums[0] <= nums[mid]:
                if nums[0] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            else:
                if nums[mid] < target <= nums[-1]:
                    l = mid + 1
                else:
                    r = mid - 1
        return -1

# 因为只有一次旋转，所以必定是两段各自有序的数组
# 二分时多一个判断条件，认为如果 最左边的值小于当前遍历的中间值
# 则认为至少 0 ~ mid 这段数组是有序的
# 否则认为 mid ~ end 这段数组有序
# 区分情况后，在判断一个有序数组中 target 目标是否在当前有序的数组内部
# 若在，缩小范围在 l ~ mid 范围内，因为此时 mid 左边必定有 target,缩减 r 范围
# 否则认为在 mid 之外，在那个不那么有序的数组中，那此时之需要挪动 l 范围即可
# 下次计算 mid ，再判断新 0 到新 mid 是否有序
# 这个方法说明了，一定要找到一个部分有序的区间，来判断 target 是否在范围内
# 再挪动 l 和 r，而不是在一个全局无序的范围内决定移动 l 还是 r
# 若 target 不在当前部分有序区间内，那去找另一个区间就好了。