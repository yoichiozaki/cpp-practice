class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        N = len(bombs)
        G = defaultdict(list)
        ans = 0
        
        for i in range(N):
            for j in range(N):
                if i == j:
                    continue
                if (bombs[i][0] - bombs[j][0]) ** 2 + (bombs[i][1] - bombs[j][1]) ** 2 <= bombs[i][2] ** 2:
                    G[i].append(j)
        
        def dfs(node, has_visited):
            for neighbor in G[node]:
                if neighbor in has_visited:
                    continue
                has_visited.add(neighbor)
                dfs(neighbor, has_visited)
        
        for node in range(N):
            has_visited = set([node])
            dfs(node, has_visited)
            ans = max(ans, len(has_visited))
        
        return ans