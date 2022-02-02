class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        # 葉っぱから引きちぎる
        if n == 1:
            return [0]

        G = [set() for _ in range(n)]
        for edge in edges:
            u = edge[0]
            v = edge[1]
            G[u].add(v)
            G[v].add(u)

        leaf = [node for node in range(n) if len(G[node]) == 1]

        while 2 < n:
            n -= len(leaf)
            new_leaf = []
            for u in leaf:
                v = G[u].pop()
                G[v].remove(u)
                if len(G[v]) == 1:
                    new_leaf.append(v)
            leaf = new_leaf

        return leaf
