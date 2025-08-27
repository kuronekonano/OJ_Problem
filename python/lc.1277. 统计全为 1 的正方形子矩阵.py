class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        ans = 0
        dp = [[0 for _ in range(len(matrix[0]))] for _ in matrix]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if i == 0 or j == 0:
                    ans += matrix[i][j]
                    continue
                if matrix[i][j] == 1:
                    matrix[i][j] = min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]) + 1
                    ans += matrix[i][j]
        return ans