# BFS で階層ごとの要素のリストを取ってから、それらが昇順になるまでに必要な交換の回数を数える
# 要素に重複のない数列をソートするときに、交換の回数が最小で何回かを数えるアルゴリズムがよくわからない。

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        suspended = [root]
        ans = 0
        while len(suspended) != 0:
            values = [node.val for node in suspended]
            pos = {value: idx for idx, value in enumerate(sorted(values))}
            visited = [False for _ in range(len(suspended))]
            for i in range(len(values)):
                swap_count = 0
                while not visited[i] and i != pos[values[i]]:
                    visited[i] = True
                    i = pos[values[i]]
                    swap_count += 1
                ans += max(0, swap_count - 1)

            next_suspended = []
            for i in range(len(suspended)):
                node = suspended[i]
                if node.left is not None:
                    next_suspended.append(node.left)
                if node.right is not None:
                    next_suspended.append(node.right)
            suspended = next_suspended
        return ans