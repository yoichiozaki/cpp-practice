# 数字を頂点として操作を辺とするグラフが書けてその最短経路問題に帰着できる
class Solution:
    def minimumOperations(self, nums: List[int], start: int, goal: int) -> int:
        has_visited = set()
        ans = 0
        queue = deque()
        queue.append(start)
        while len(queue) != 0:
            size = len(queue)
            for _ in range(size):
                n = queue.popleft()
                if n == goal:
                    return ans
                if n < 0 or 1000 < n or n in has_visited:
                    continue
                has_visited.add(n)
                for num in nums:
                    queue.append(n + num)
                    queue.append(n - num)
                    queue.append(n ^ num)
            ans += 1
        return -1