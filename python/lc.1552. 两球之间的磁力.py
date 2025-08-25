class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        def check(val):
            cnt = 1
            pre = position[0]
            for i in position[1:]:
                if i - pre >= val:
                    cnt += 1
                    pre = i
            return cnt >= m


        position.sort()
        l, r = 0, position[-1] - position[0]
        while l <= r:
            mid = (l + r) >> 1
            if check(mid):
                l = mid + 1
                ans = mid
            else:
                r = mid - 1
        return ans