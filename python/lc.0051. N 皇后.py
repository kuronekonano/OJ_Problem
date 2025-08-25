class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        vis_row = [False for _ in range(n)]
        vis_left = [False for _ in range(n + 20)]
        vis_right = [False for _ in range(n + 20)]
        ans = []

        def dfs(cur, queen):
            nonlocal ans
            if cur == n:
                ans.append([_ for _ in queen])
                return
            for i in range(n):
                if not vis_row[i] and not vis_left[10 + cur - i] and not vis_right[cur + i]:
                    vis_row[i] = True
                    vis_right[cur + i] = True
                    vis_left[10 + cur - i] = True
                    queen.append((cur, i))
                    dfs(cur + 1, queen)
                    queen.pop()
                    vis_row[i] = False
                    vis_right[cur + i] = False
                    vis_left[10 + cur - i] = False

        dfs(0, [])
        res = []
        for case in ans:
            ma = [["." for _ in range(n)] for _ in range(n)]
            for i, j in case:
                ma[i][j] = "Q"
            res.append(["".join(i) for i in ma])
        return res