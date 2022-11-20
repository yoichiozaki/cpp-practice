from heapq import heapify, heappop, heappush

class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        firstQ = costs[:candidates]
        lastQ = costs[max(candidates, len(costs) - candidates):]
        heapify(firstQ), heapify(lastQ)
        ans = 0
        first_tail = candidates
        last_head = len(costs) - candidates - 1
        for _ in range(k):
            if not lastQ or firstQ and firstQ[0] <= lastQ[0]:
                ans += heappop(firstQ)
                if first_tail <= last_head:
                    heappush(firstQ, costs[first_tail])
                    first_tail += 1
            else:
                ans += heappop(lastQ)
                if first_tail <= last_head:
                    heappush(lastQ, costs[last_head])
                    last_head -= 1
        return ans