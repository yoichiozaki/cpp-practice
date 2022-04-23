class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        G = defaultdict(list)
        goals = []
        for i in range(len(arr)):
            if arr[i] == 0:
                goals.append(i)
                continue
            if i + arr[i] < len(arr):
                G[i].append(i + arr[i])
            if 0 <= i - arr[i]:
                G[i].append(i - arr[i])
        suspended = [start]
        has_visited = set()
        while len(suspended) != 0:
            n = suspended.pop()
            if n in has_visited:
                continue
            has_visited.add(n)
            for nbr in G[n]:
                suspended.append(nbr)
        return any(goal in has_visited for goal in goals)


class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        G = defaultdict(list)
        goals = []
        for i in range(len(arr)):
            if arr[i] == 0:
                goals.append(i)
                continue
            if i + arr[i] < len(arr):
                G[i].append(i + arr[i])
            if 0 <= i - arr[i]:
                G[i].append(i - arr[i])
        suspended = [start]
        has_visited = set()
        while len(suspended) != 0:
            n = suspended.pop(0)
            if n in has_visited:
                continue
            has_visited.add(n)
            for nbr in G[n]:
                suspended.append(nbr)
        return any(goal in has_visited for goal in goals)


class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if 0 <= start < len(arr) and 0 <= arr[start]:
            arr[start] *= -1
            return arr[start] == 0 or self.canReach(arr, start + arr[start]) or self.canReach(arr, start - arr[start])
        return False