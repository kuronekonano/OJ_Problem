class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stack, left, right = [], [0 for _ in range(n)], [n for _ in range(n)]
        for i in range(n):
            while stack != [] and heights[stack[-1]] >= heights[i]:
                right[stack[-1]] = i
                stack.pop()
            left[i] = -1 if stack == [] else stack[-1]
            stack.append(i)

        ans = heights[0]
        for i in range(n):
            ans = max(ans, (right[i] - left[i] - 1) * heights[i])
        return ans

# 通过单调栈记录一个递增序列
# 表示以当前高度为最低点时形成的最长矩形的左边界和右边界的 下标
# 最后用左右边界之差（矩形长度）* 当前认为的最低高度，即以当前高度为最低高度的最大矩形
# 更新这个 max ans 即结果