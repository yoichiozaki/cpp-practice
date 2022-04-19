class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        # day iまでの旅程をカバーするチケットの最安コスト
        dp = [float("inf") for i in range(0, 370)]
        dp[0] = 0
        last_day = max(days)
        days = set(days)
        for day in range(1, 370):
            if day == last_day + 1:
                return dp[last_day]
            if day in days:
                dp[day] = min(
                    dp[max(0, day - 1)] + costs[0],
                    dp[max(0, day - 7)] + costs[1],
                    dp[max(0, day - 30)] + costs[2]
                )
            else:
                dp[day] = dp[day - 1]


class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        cost = 0
        last7 = []
        last30 = []
        for day in days:
            while len(last7) != 0 and last7[0][0] + 7 <= day:
                last7.pop(0)
            while len(last30) != 0 and last30[0][0] + 30 <= day:
                last30.pop(0)
            last7.append((day, cost + costs[1]))
            last30.append((day, cost + costs[2]))
            cost = min(
                cost + costs[0],
                last7[0][1],
                last30[0][1]
            )
        return cost