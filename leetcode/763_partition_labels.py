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

    
    # tail_candidateを毎回求めるのではなくて最初に計算しておくと少し効率が良くなる
    # 前から順番に見ていくことで出来上がる配列は最大値が格納されることになるという事実はあたりまえだけど意外と盲点かもしれない
    class Solution:
        def partitionLabels(self, s: str) -> List[int]:
            ans = []
            head = 0
            tail = 0
            last_pos = [0 for _ in range(26)]
            for pos, ch in enumerate(s):
                last_pos[ord(ch) - ord('a')] = pos
            for ptr in range(len(s)):
                tail_candidate = last_pos[ord(s[ptr]) - ord('a')]
                if tail_candidate < tail:
                    continue
                tail = max(tail, tail_candidate)
                if ptr == tail:
                    ans.append(tail - head + 1)
                    head = tail + 1
                    tail = tail + 1
            return ans