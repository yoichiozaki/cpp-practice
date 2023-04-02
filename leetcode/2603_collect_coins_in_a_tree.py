class Solution:
    def collectTheCoins(self, coins: List[int], edges: List[List[int]]) -> int:
        N = len(coins)
        tree = [set() for _ in range(N)]
        for edge in edges:
            tree[edge[0]].add(edge[1])
            tree[edge[1]].add(edge[0])
        
        leaves = []
        for node in range(N):
            u = node
            while len(tree[u]) == 1 and coins[u] == 0: # u is leaf with no coins
                v = tree[u].pop()
                tree[v].remove(u)
                u = v
            if len(tree[u]) == 1:
                leaves.append(u)
        
        for _ in range(2, 0, -1):
            tmp = []
            for u in leaves:
                if len(tree[u]) == 1:
                    v = tree[u].pop()
                    tree[v].remove(u)
                    if len(tree[v]) == 1:
                        tmp.append(v)
            leaves = tmp
        
        ans = 0
        for i in range(N):
            ans += len(tree[i])
        return ans