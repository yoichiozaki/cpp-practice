class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        cnt = Counter(s)
        return int(100 * cnt[letter] / len(s)) 