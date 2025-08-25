class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        for i in range(n >> 1):
            for j in range((n + 1) >> 1):
                cur_i, cur_j = i, j
                last = matrix[cur_i][cur_j]
                # print("=")
                for _ in range(4):
                    nxt_i, nxt_j = cur_j, n - cur_i - 1
                    tmp = matrix[nxt_i][nxt_j]
                    matrix[nxt_i][nxt_j] = last
                    last = tmp
                    # print(matrix[nxt_i][nxt_j])
                    # print(f"({cur_i},{cur_j})  ->  ({nxt_i},{nxt_j})")
                    cur_i, cur_j = nxt_i, nxt_j
        return matrix