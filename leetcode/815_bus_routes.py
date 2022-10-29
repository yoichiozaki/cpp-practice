# バス1路線ごとにまとめて一つの頂点にしてBFS
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        
        G = defaultdict(set)
        N = len(routes)
        for i, route_i in enumerate(routes):
            for j in range(i + 1, N):
                route_j = routes[j]
                if any(station in route_j for station in route_i):
                    G[i].add(j)
                    G[j].add(i)
        routes = map(set, routes)
        
        has_visited = set()
        targets = set()
        for node, route in enumerate(routes):
            if source in route:
                has_visited.add(node)
            if target in route:
                targets.add(node)
        
        queue = deque([(node, 1) for node in has_visited])
        while len(queue) != 0:
            node, step = queue.popleft()
            if node in targets:
                return step
            for neighbor in G[node]:
                if neighbor not in has_visited:
                    has_visited.add(neighbor)
                    queue.append((neighbor, step + 1))

        return -1
        