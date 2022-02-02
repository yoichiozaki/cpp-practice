class Solution:
    def numSplits(self, s: str) -> int:
        ans = 0
        left_counter = Counter()
        right_counter = Counter(s)

        for ch in s:
            left_counter[ch] += 1
            right_counter[ch] -= 1
            if right_counter[ch] == 0:
                del right_counter[ch]

            if len(right_counter) == len(left_counter):
                ans += 1
        return ans
