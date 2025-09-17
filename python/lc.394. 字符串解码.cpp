def decodeString(self, s: str) -> str:
    def dfs(idx):
        it = idx
        cnt = 0
        tmp = ""
        while it < len(s):
            if s[it] in "abcdefghijklmnopqrstuvwxyz":
                tmp += s[it]
            if s[it] in "1234567890":
                cnt = cnt * 10 + int(s[it])
            if s[it] == "]":
                return tmp, it
            if s[it] == "[":
                in_tmp, it = dfs(it+1)
                tmp += cnt * in_tmp
                cnt = 0
            it += 1
        return tmp, it
    return dfs(0)[0]

class Solution:
    def decodeString2(self, s: str) -> str:
        stack = []
        cache = []
        i = 0
        n = len(s)
        cnt = 0
        tmp_str = ""
        ans = []
        while i < n:
            if s[i] in "0123456789":
                cnt = cnt * 10 + int(s[i])
            if s[i] == "[":
                stack.append(cnt)
                cnt = 0
                cache.append(tmp_str)
                tmp_str = ""
            if s[i] in "abcdefghijklmnopqrstuvwxyz":
                tmp_str += s[i]
            if s[i] == "]":
                c = stack.pop()
                tmp_str *= c
                pre = cache.pop()
                tmp_str = pre + tmp_str
            if stack == [] and tmp_str != "":
                ans.append(tmp_str)
                tmp_str = ""
            i += 1
        return "".join(ans)