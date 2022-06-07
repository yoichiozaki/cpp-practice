class Solution:
    def reorganizeString(self, s: str) -> str:
        cnt = Counter(s)
        ans = ""
        pq = [(-freq, char) for char, freq in cnt.items()]
        heapq.heapify(pq)
        
        prev_freq = 0
        prev_char = ""
        
        while len(pq) != 0:
            freq, char = heapq.heappop(pq)
            ans += char
            if prev_freq < 0:
                heapq.heappush(pq, (prev_freq, prev_char))
            freq += 1
            prev_freq = freq
            prev_char = char
        if len(ans) != len(s):
            return ""
        return ans


# 多い文字から並べていく。この時、直前に使用した文字以外で一番多い文字を使いたい。