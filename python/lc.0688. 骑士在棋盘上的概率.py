class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        ans = [[[0 for _ in range(n)] for _ in range(n)] for _ in range(k+1)]
        for s in range(k+1):
            for i in range(n):
                for j in range(n):
                    if s == 0:
                        ans[s][i][j] = 1
                        continue
                    for nx, ny in [(-1, -2), (-2, -1), (1, 2), (2, 1), (-1, 2), (-2, 1), (1, -2), (2, -1)]:
                        ni, nj = i + nx, j + ny
                        if n > ni >= 0 and n > nj >= 0:
                            ans[s][i][j] += ans[s-1][ni][nj] / 8 
        
        return ans[k][row][column]

# 预处理棋盘每一个坐标在棋盘内的概率
# 即 0 步，概率必定是 1，因为没动
# 1 步，那就由 0 步中 8 个方向上在棋盘的目标概率之和
# 即 1/8 在棋盘内，那就加上该点概率，不在，就忽略
# 以此类推 k 步概率，最后输出目标初始位置第 k 层的概率即可
# 这个 dp 其实正着想，可以用 dfs 搜索每一步而来，但这样爆搜复杂的很高
# 可以看出甚至可以两点之间来回走 k 步，此时更无法复用已经搜索过的位置的概率
# 因此想到记忆化搜索，注意记忆化搜索精髓在于将 dfs 中的 dfs(step, i + x, j + y)
# 变成 dp 的递推公式，也就是括号变成方括号