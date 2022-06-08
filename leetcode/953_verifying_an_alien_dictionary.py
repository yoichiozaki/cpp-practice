class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        alphabetical_order = dict()
        for idx, ch in enumerate(order):
            alphabetical_order[ch] = idx
        for i in range(len(words) - 1):
            for j in range(len(words[i])):
                if j >= len(words[i + 1]):
                    return False
                if words[i][j] != words[i + 1][j]:
                    if alphabetical_order[words[i][j]] > alphabetical_order[words[i + 1][j]]:
                        return False
                    else:
                        break
        return True