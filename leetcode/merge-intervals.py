# Sort
# Time: O(n log n)
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda ele: ele[0])

        merged = []
        for interval in intervals:
            if len(merged) == 0 or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged


# Graph
# Time: O(n^2)
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        def is_overlapped(a, b):
            return a[0] <= b[1] and b[0] <= a[1]

        def build_graph(intervals):
            G = collections.defaultdict(list)
            for i, interval in enumerate(intervals):
                for j in range(i + 1, len(intervals)):
                    if is_overlapped(interval, intervals[j]):
                        G[tuple(interval)].append(intervals[j])
                        G[tuple(intervals[j])].append(interval)
            return G

        def merge_nodes(nodes):
            merged_start = min(node[0] for node in nodes)
            merged_end = max(node[1] for node in nodes)
            return [merged_start, merged_end]

        def get_components(G, intervals):
            has_visited = set()
            num_comps = 0
            comps_to_nodes = collections.defaultdict(list)

            def dfs(root):
                stack = [root]
                while len(stack) != 0:
                    curr = tuple(stack.pop())
                    if curr not in has_visited:
                        comps_to_nodes[num_comps].append(curr)
                        has_visited.add(curr)
                        stack += G[curr]

            for interval in intervals:
                if tuple(interval) not in has_visited:
                    dfs(interval)
                    num_comps += 1

            return comps_to_nodes, num_comps

        G = build_graph(intervals)
        comps_to_nodes, num_comps = get_components(G, intervals)
        return [merge_nodes(comps_to_nodes[comp]) for comp in range(num_comps)]
