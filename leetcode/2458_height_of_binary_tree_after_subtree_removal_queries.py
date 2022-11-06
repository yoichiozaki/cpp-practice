# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def treeQueries(self, root: Optional[TreeNode], queries: List[int]) -> List[int]:
        depths = defaultdict(int)
        heights = defaultdict(int)

        def dfs(root, depth):
            if root is None:
                return -1
            depths[root.val] = depth
            height = max(dfs(root.left, depth + 1), dfs(root.right, depth + 1)) + 1
            heights[root.val] = height
            return height

        dfs(root, 0)
        nodes_by_level = defaultdict(list)
        for val, depth in depths.items():
            nodes_by_level[depth].append((-heights[val], val))
            nodes_by_level[depth].sort()
            if len(nodes_by_level[depth]) > 2:
                nodes_by_level[depth].pop()
        
        ans = []
        for query in queries:
            depth = depths[query]
            if len(nodes_by_level[depth]) == 1:
                ans.append(depth - 1)
            elif nodes_by_level[depth][0][1] == query:
                ans.append(-nodes_by_level[depth][1][0] + depth)
            else:
                ans.append(-nodes_by_level[depth][0][0] + depth)
        return ans