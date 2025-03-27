class Solution:
    def myAtoi(self, s: str) -> int:
        maxn = 2**31 - 1
        minn = -2**31
        s = s.strip()
        if not s:
            return 0
        if s[0] not in '+-0123456789':
            return 0
        ans = 0
        neg_flag = False
        if s[0] == '-':
            neg_flag = True
        if s[0] in '+-':
            s = s[1:]
        for i in s:
            if ans == 0 and not i.isdigit():
                return 0
            if not i.isdigit():
                break
            ans = ans * 10 + int(i)
            
            if ans > maxn+10:
                break
        ans = ans if not neg_flag else -ans
        if ans < minn:
            ans = minn
        if ans > maxn:
            ans = maxn
        return ans
    
if __name__ == '__main__':
    s = Solution()
    print(s.myAtoi("42"))
    print(s.myAtoi("0-1"))
    print(s.myAtoi("-91283472332"))