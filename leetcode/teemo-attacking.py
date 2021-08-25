class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        ans = 0
        for i in range(len(timeSeries) - 1):
            ans += min(timeSeries[i+1] - timeSeries[i], duration)
        ans += duration
        return ans
