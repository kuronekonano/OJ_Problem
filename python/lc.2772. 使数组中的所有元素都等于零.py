class Solution:
    def checkArray(self, nums: List[int], k: int) -> bool:
        down = [0 for _ in range(len(nums)+1)]
        cur_down = 0
        for i, v in enumerate(nums):
            cur_down += down[i] # 计算差分差多少
            v += cur_down # 扣除当前值
            if v == 0:  # 无需差分操作，或者已经完成扣除操作
                continue
            if v < 0 or i + k >= len(down): # 若使用突出值干掉当前位已经低于0时，必定不过，若由当前位置往后k位超出len也不通过，实际上此处是将两个不相干的if写一起用 or 连接
                return False
            cur_down -= v   # 差分 start,由此开始剪掉突出值
            down[i+k] += v  # 差分 end，由此结束突出值，把开头去掉的突出值加回来
        return True
            