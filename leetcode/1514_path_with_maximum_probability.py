# コストの与え方をひねったdijkstra法
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        G = {i: set() for i in range(n)}
        for i in range(len(edges)):
            edge = edges[i]
            succ_prob = succProb[i]
            G[edge[0]].add((edge[1], succ_prob))
            G[edge[1]].add((edge[0], succ_prob))
        
        has_visited = set()
        suspended = []
        prob = [float("-inf") for i in range(n)]
        
        has_visited.add(start)
        suspended.append((-1.0, start))
        prob[start] = 1.0
        
        while len(suspended) != 0:
            p, node = heappop(suspended)
            p = -p
            has_visited.add(node)
            for (neighbor, succ_prob) in G[node]:
                if neighbor not in has_visited and prob[node] * succ_prob > prob[neighbor]:
                    prob[neighbor] = prob[node] * succ_prob
                    heappush(suspended, (-prob[neighbor], neighbor))
        
        return prob[end] if prob[end] != float("-inf") else 0.0
