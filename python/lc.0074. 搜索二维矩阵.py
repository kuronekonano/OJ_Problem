class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = len(matrix[0]), len(matrix)
        print("======")
        def binary_search(right, c = None):
            l, r = 0, right
            while l < r:
                mid = l + r >> 1
                mid_value = matrix[c][mid] if c is not None else matrix[mid][0]
                if mid_value < target:
                    l = mid + 1
                else:
                    r = mid
            print(l)
            return l
        
        index_row = max(binary_search(col), 0)
        if index_row >= col or matrix[index_row][0] > target:
            index_row -= 1
        print("index_row:", index_row)
        if matrix[index_row][0] == target:
            return True
        index_col = min(binary_search(row, index_row), row - 1)
        print("index_col:", index_col)
        if matrix[index_row][index_col] == target:
            return True
        return False