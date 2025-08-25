class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        step = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        ans = set()
        check_set = set()
        vis = []
        def dfs(cur_i, cur_j, from_l):
            if (cur_i, cur_j) in check_set and not from_l:
                ans.add((cur_i, cur_j))
            for step_i, step_j in step:
                nx_i = cur_i + step_i
                nx_j = cur_j + step_j
                if nx_i < 0 or nx_j < 0:
                    continue
                if nx_i >= len(heights) or nx_j >= len(heights[0]):
                    continue
                if vis[nx_i][nx_j] == 0 and heights[nx_i][nx_j] >= heights[cur_i][cur_j]:
                    vis[nx_i][nx_j] = 1
                    if from_l:
                        check_set.add((nx_i, nx_j))
                    else:
                        if (nx_i, nx_j) in check_set:
                            ans.add((nx_i, nx_j))
                    dfs(nx_i, nx_j, from_l)
            
    
        for i, r in enumerate(heights):
            vis = [[0 for _ in heights[0]] for _ in heights]
            check_set.add((i, 0))
            dfs(i, 0, True)
        for i, c in enumerate(heights[0]):
            vis = [[0 for _ in heights[0]] for _ in heights]
            check_set.add((0, i))
            dfs(0, i, True)
        print(check_set)
        for i, r in enumerate(heights):
            vis = [[0 for _ in heights[0]] for _ in heights]
            dfs(i, len(heights[0]) - 1, False)
        for i, c in enumerate(heights[0]):
            vis = [[0 for _ in heights[0]] for _ in heights]
            dfs(len(heights) - 1, i, False)
        return [[i, j] for i, j in ans]
        