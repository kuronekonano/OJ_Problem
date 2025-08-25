class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        ans = []
        m = len(mat)
        n = len(mat[0])
        num = len(mat) * len(mat[0])
        i = j = 0

        def add_value(i, j):
            nonlocal ans, num
            if len(ans) == num:
                return False
            ans.append(mat[i][j])
            return True

        ans.append(mat[i][j])

        while len(ans) < num:
            if j == n - 1:
                i += 1
            else: 
                j += 1
            if not add_value(i, j):
                break
            while i < m - 1 and j > 0:
                i += 1;j -= 1
                if not add_value(i, j):
                    break
            if i == m - 1:
                j += 1
            else:
                i += 1
            if not add_value(i, j):
                break
            while i > 0 and j < n - 1:
                i -= 1;j += 1
                if not add_value(i,j):
                    break
            
        return ans

            


