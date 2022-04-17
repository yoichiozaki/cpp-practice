class Solution:
    def maximumPopulation(self, logs: List[List[int]]) -> int:
        delta = [0 for _ in range(3000)]
        ans = 0
        for log in logs:
            start = log[0]
            end = log[1]
            delta[start] += 1
            delta[end] -= 1
        for year in range(1950, 2051):
            delta[year] += delta[year - 1]
            ans = year if delta[year] > delta[ans] else ans
        return ans
        