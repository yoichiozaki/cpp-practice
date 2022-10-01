# N = length of list of words, M = average length of words
# Time: O(N*M + N*N)
# Space: O(M)
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        masks = [0 for _ in range(len(words))]
        ans = 0
        for i, word in enumerate(words):
            for ch in word:
                masks[i] |= 1 << (ord(ch) - ord('a'))
        for i in range(len(words)):
            for j in range(i):
                if masks[i] & masks[j] == 0:
                    ans = max(ans, len(words[i] * len(words[j])))
        return ans