class Solution:  # 拓扑排序
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        mp = [[] for _ in range(numCourses + 2)]
        inp_count = [0 for _ in range(numCourses + 2)]
        for cour in prerequisites:
            dst = cour[0]
            inp_count[cour[0]] += len(cour) - 1
            for c in cour[1:]:
                mp[c].append(dst)

        q = []
        for i in range(numCourses):
            if inp_count[i] == 0:
                q.append(i)
        sort_count = 0
        while q:
            cur = q.pop(0)
            sort_count += 1
            for i in mp[cur]:
                inp_count[i] -= 1
                if inp_count[i] == 0:
                    q.append(i)
        return sort_count == numCourses
