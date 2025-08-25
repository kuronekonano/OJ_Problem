class Solution:
    def checkValidString(self, s: str) -> bool:
        stack_qu = []
        stack_st = []
        for i in range(len(s)):
            if s[i] == "(":
                stack_qu.append(i)
            if s[i] == "*":
                stack_st.append(i)
            if s[i] == ")":
                if len(stack_qu):
                    stack_qu.pop()
                elif len(stack_st):
                    stack_st.pop()
                else:
                    return False
        while len(stack_qu) and len(stack_st):
            qu = stack_qu.pop()
            st = stack_st.pop()
            if st < qu:
                return False
        return False if len(stack_qu) else True