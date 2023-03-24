class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        d1 = dict()
        d2 = dict()
        for ch1, ch2 in zip(s, t):
            if ch1 not in d1 and ch2 not in d2:
                d1[ch1] = ch2
                d2[ch2] = ch1
            elif ch1 not in d1 or ch2 not in d2 or d1[ch1] != ch2 or d2[ch2] != ch1:
                return False
        return True