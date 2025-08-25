# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def find(self, root_value, left, right):
        for i in range(left, right):
            if self.inorder[i] == root_value:
                return i
        return 0

    def halfpath(self, pre_left, pre_right, in_left, in_right):
            if pre_left == pre_right:
                return None
            cur = TreeNode(self.preorder[pre_left])
            if in_left == in_right:
                return None
            root_index = self.find(cur.val, in_left, in_right)
            left_subtree_len = root_index - in_left
            cur.left = self.halfpath(pre_left + 1, pre_left + left_subtree_len + 1, in_left, root_index)
            cur.right = self.halfpath(pre_left + left_subtree_len + 1, pre_right, root_index + 1, in_right)
            return cur

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 0:
            return None
        self.preorder = preorder
        self.inorder = inorder
        return self.halfpath(0, len(preorder), 0, len(inorder))

        
        