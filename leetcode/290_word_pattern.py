class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(words) != len(pattern):
            return False

        p2w, w2p = dict(), dict()
        for p, w in zip(pattern, words):
            if p not in p2w and w not in w2p:
                p2w[p] = w
                w2p[w] = p
            elif p not in p2w or w not in w2p or p2w[p] != w or w2p[w] != p:
                return False

        return True