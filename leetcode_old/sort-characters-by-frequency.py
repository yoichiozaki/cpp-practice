# 言われたとおりにソートする
class Solution:
    def frequencySort(self, s: str) -> str:
        cnt = Counter(s)
        ls = list(s)
        ls.sort(key=lambda x: (-cnt[x], x))
        return "".join(ls)


# top-k-frequent-elements.pyの優先度付きキューを使うバージョン
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
