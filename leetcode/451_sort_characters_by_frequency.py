# Time: O(N log N)
class Solution:
    def frequencySort(self, s: str) -> str:
        cnt = Counter(s)
        freqs = [(-freq, ch) for ch, freq in cnt.items()]
        freqs.sort()
        ans = ""
        for (freq, ch) in freqs:
            freq = -freq
            ans += ch * freq
        return ans


# Time: O(N), heapifyはO(N)!
class Solution:
    def frequencySort(self, s: str) -> str:
        counter = Counter(s)
        pq = [(-freq, ch) for (ch, freq) in counter.items()]
        heapq.heapify(pq)
        ans = ""
        while len(pq) != 0:
            (freq, ch) = heapq.heappop(pq)
            ans += ch * (-freq)
        return ans