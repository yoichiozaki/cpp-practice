class Solution:
    def miceAndCheese(self, reward1: List[int], reward2: List[int], k: int) -> int:
        class FixedSizeMaxHeap:
            def __init__(self, size):
                self.lst = []
                self.size = size
                heapify(self.lst)
            def push(self, element):
                if len(self.lst) < self.size:
                    heappush(self.lst, element)
                else:
                    heappushpop(self.lst, element)
            def top(self):
                return nlargest(self.lst, self.size)
        deltas = [reward1[i] - reward2[i] for i in range(len(reward1))]
        pq = FixedSizeMaxHeap(k)
        for delta in deltas:
            pq.push(delta)
        return sum(pq.lst) + sum(reward2)
        