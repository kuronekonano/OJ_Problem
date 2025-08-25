class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        def dfs(vis, n, tmp):
            if len(tmp) == len(n):
                ans.append([_ for _ in tmp])
                return 
            for i, v in enumerate(n):
                if vis[i]:
                    continue
                vis[i] = True
                tmp.append(v)
                dfs(vis, n, tmp)
                tmp.pop()
                vis[i] = False
        dfs([False for _ in range(len(nums))], nums, [])
        return ans