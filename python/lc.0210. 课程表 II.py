class Solution:  # 拓扑排序
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        mp = [[] for _ in range(numCourses)]
        inp = [0] * numCourses
        for cour in prerequisites:
            dst = cour[0]
            inp[dst] += len(cour) - 1
            for c in cour[1:]:
                mp[c].append(dst)
        q = []
        for i in range(numCourses):
            if inp[i] == 0:
                q.append(i)
        ans = []
        while q:
            cur = q.pop(0)
            ans.append(cur)
            for i in mp[cur]:
                inp[i] -= 1
                if inp[i] == 0:
                    q.append(i)
        return ans if len(ans) == numCourses else []
