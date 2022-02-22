class Solution:
    def checkAlmostEquivalent(self, word1: str, word2: str) -> bool:
        cnt1 = Counter("abcdefghijklmnopqrstuvwxyz")
        cnt2 = Counter("abcdefghijklmnopqrstuvwxyz")
        for ch in word1:
            cnt1[ch] += 1
        for ch in word2:
            cnt2[ch] += 1
        for ch in cnt1:
            if abs(cnt1[ch] - cnt2[ch]) >= 4:
                return False
        return True
        # return all(v < 4 for v in ((Counter(w1) - Counter(w2)) + (Counter(w2) - Counter(w1))).values())
