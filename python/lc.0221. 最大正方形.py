class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        ans = 0
        for i, row in enumerate(matrix):
            for j, v in enumerate(row):
                if i == 0 or j==0:
                    ans = max(ans, int(matrix[i][j]))
                    continue
                if int(matrix[i][j]) == 1:
                    matrix[i][j] = min(int(matrix[i-1][j]), int(matrix[i][j-1]), int(matrix[i-1][j-1])) + 1
                ans = max(ans, int(matrix[i][j]))
        
        return ans * ans