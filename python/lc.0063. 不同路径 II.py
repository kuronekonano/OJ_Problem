class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        a =[[0 for _ in range(len(obstacleGrid[0]))] for _ in range(len(obstacleGrid))]
        for i in range(len(obstacleGrid)):
            if obstacleGrid[i][0] == 1:
                break
            a[i][0] = 1
        for i in range(len(obstacleGrid[0])):
            if obstacleGrid[0][i] == 1:
                break
            a[0][i] = 1
        for i in range(1,len(obstacleGrid)):
            for j in range(1, len(obstacleGrid[0])):
                if obstacleGrid[i][j] ==1:
                    continue
                a[i][j] = a[i-1][j] + a[i][j-1]
        return a[-1][-1]