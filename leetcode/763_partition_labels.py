# 尺取り法を実装できますか？という問い
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ans = []
        head = 0
        tail = 0
        for ptr in range(len(s)):
            tail_candidate = len(s) - 1
            while s[ptr] != s[tail_candidate]:
                tail_candidate -= 1
            tail = max(tail, tail_candidate)
            if ptr == tail:
                ans.append(tail - head + 1)
                head = tail + 1
                tail = tail + 1
        return ans