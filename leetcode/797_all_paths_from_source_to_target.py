class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        queue = deque()
        queue.appendleft((0, []))
        paths = []
        while len(queue) != 0:
            node, path = queue.pop()
            if node == len(graph) - 1:
                paths.append(path + [node])
                continue
            else:
                for neighbor in graph[node]:
                    queue.appendleft((neighbor, path + [node]))
        return paths