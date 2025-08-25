class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        a = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(n):
            a[0][i]=1
        for i in range(m):
            a[i][0]= 1
        print(len(a), len(a[0]))
        for i in range(1,m):
            for j in range(1, n):
                a[i][j] = a[i -1][j] + a[i][j-1]
        return a[m-1][n-1]