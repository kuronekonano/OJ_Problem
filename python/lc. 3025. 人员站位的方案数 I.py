class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        ans = 0
        points.sort(key=lambda x: (x[0], -x[1]))
        for i in range(len(points) - 1):
            max_i = -1
            for j in range(i + 1, len(points)):
                if points[j][1] <= points[i][1] and points[j][1] > max_i:
                    ans += 1
                    max_i = max(points[j][1], max_i)

        return ans

# 首先按照 x 轴排序，再按 y 轴排序，这样遍历顺序必定从左上角开始
# 遍历过程中，如果遇到 j 点比当前 i 点的 y 值大，就跳过，否则就认为是一个计数
# 另外如何判断 i 和 j 之间是否有点，可以知道如果一个点在两者之间，必定作为过一次计数
# 而新未来遍历点 j 点，必须在已经遍历过的 j 点的 y 值之上
# 因此对于每个 i 点记录一个 j 点的最大 y 值，每次计数增加，更新这个 y 值，一旦有新的 j 点 y 值大于 max
# 说明可以计数，否则低于 max 的 y 值将视作中间有过其他的点在两者组成的矩形之间