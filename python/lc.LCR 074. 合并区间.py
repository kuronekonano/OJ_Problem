class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        ans = []
        for i in intervals:
            if not ans:
                ans.append(i)
                continue
            if i[0] <= ans[-1][1]:
                ans[-1][1] = max(ans[-1][1], i[1])
            else:
                ans.append(i)
        
        return ans