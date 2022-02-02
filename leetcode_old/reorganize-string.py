# heapを使って一番残ってる文字を追跡しながら答えの文字列を生成していく
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


# 一番多い文字から一つ空けて並べる
class Solution:
    def reorganizeString(self, s: str) -> str:
        counter = [0 for _ in range(26)]
        for i in range(len(s)):
            counter[ord(s[i]) - ord('a')] += 1

        max_freq = 0
        char = 0
        for i in range(len(counter)):
            if counter[i] > max_freq:
                max_freq = counter[i]
                char = i

        # 過半数を占める文字があったら無理
        if max_freq > (len(s) + 1) // 2:
            return ""

        ans = ["" for _ in range(len(s))]
        idx = 0
        while counter[char] > 0:
            ans[idx] = chr(char + ord('a'))
            idx += 2
            counter[char] -= 1

        for i in range(len(counter)):
            while counter[i] > 0:
                if idx >= len(ans):
                    idx = 1
                ans[idx] = chr(i + ord('a'))
                idx += 2
                counter[i] -= 1

        return "".join(ans)
