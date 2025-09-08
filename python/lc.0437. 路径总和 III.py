# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        counter = defaultdict(int)
        counter[0] = 1
        ans = 0
        def dfs(cur, presum):
            nonlocal ans
            if cur is None:
                return 
            presum += cur.val
            ans += counter[presum - targetSum]
            counter[presum] += 1
            dfs(cur.left, presum)
            dfs(cur.right, presum)
            counter[presum] -= 1
        dfs(root, 0)
        return ans
            
# 巨他妈坑的傻逼题边界样例
# [1], 0 空路径不算路径， 1 - 0 = 1 但是此时 1 并不算一条路径
# 由此可知必须先算完 ans 累加计数，再增加 counter 的计数，先后顺序不对会造出不存在的路径
# [0, 1, 1] 1 此时解有 4 个，左右两条路径，再加上两个 1 本身
# 由此可知一个前缀和真的会被多条路径复用，所以必须用计数器来记录每一个前缀和出现次数
# 而不是判断出现过就 +1 ，必须是 counter 数量个出现次数，因为有 0 存在，导致有多条路径在同一个前缀和上

# 最后方法就是 dfs 求路径前缀和，注意此时减去 target sum，找到目标前缀和的计数次数
# 而非枚举任意两个前缀和试图通过枚举路径的方式匹配上 targetSum