# DFSで全探索しながら「左側の子無し」であることを確認する
# Time: O(N) ... 全頂点に訪問するから
# Space: O(log N) ... 再帰関数が木の高さだけ呼ばれる
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        def dfs(node, is_left):
            if node is None:
                return 0
            if node.left is None and node.right is None:
                return node.val if is_left else 0
            return dfs(node.left, True) + dfs(node.right, False)
        return dfs(root, False)


# stackでDFSを実装した場合の解答
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        ans = 0
        stack = [(root, False)]
        while len(stack) != 0:
            node, is_left = stack.pop()
            if node.left is None and node.right is None and is_left:
                ans += node.val
            if node.left is not None:
                stack.append((node.left, True))
            if node.right is not None:
                stack.append((node.right, False))
        return ans


# queueでBFSを実装した場合の解答
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        ans = 0
        queue = [(root, False)]
        while len(queue) != 0:
            node, is_left = queue.pop(0)
            if node.left is None and node.right is None and is_left:
                ans += node.val
            if node.left is not None:
                queue.append((node.left, True))
            if node.right is not None:
                queue.append((node.right, False))
        return ans


# Morris traversal：空間計算量O(1)で全頂点をin-orderで探索する．イメージとしては左部分木の右端から根への一時的なポインタを作りながら木を下に降りていき，葉ノードに到達したらそこから右へ右へ進んでいくとin-orderになっている．右へ右へ進む途中で一時的に張ったポインタを消しながら進む．
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        ans = 0
        while root is not None:
            if root.left is not None:
                prev = root.left
                while prev.right is not None and prev.right is not root:
                    prev = prev.right
                if prev.right is None:  # in-order順でrootの直前のノードがprevになっている
                    prev.right = root  # 一時的なリンクを張る
                    root = root.left
                else:
                    prev.right = None  # ここで一時的に張ったリンクを消してる
                    if prev is root.left and prev.left is None:
                        ans += prev.val
                    root = root.right
            else:  # ここに入り込む時点でrootは左端の葉ノード
                root = root.right
        return ans
