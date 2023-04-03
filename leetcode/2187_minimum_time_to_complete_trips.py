class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        return bisect_left(
            range(max(time) * totalTrips),
            totalTrips,
            key=lambda t: sum(t // trip for trip in time)
        )