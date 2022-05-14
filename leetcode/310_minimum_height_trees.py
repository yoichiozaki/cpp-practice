# グラフの中心（どの頂点との距離が短い頂点）を根として木を作れば背が低くなる。グラフの末端から頂点をむしり取って真ん中に残る頂点を探す。
# 一般のグラフだった場合は、k-クリーク残るところまでむしり取れば中心が出てくる。今回の問題では与えられるのは木であるとされているのでループは発生せず、ループの発生しないクリークが残るので中心になる頂点は高々2個（1個もしくは2個）
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