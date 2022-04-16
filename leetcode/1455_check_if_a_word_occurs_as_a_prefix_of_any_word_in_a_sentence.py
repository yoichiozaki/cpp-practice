class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split(" ")
        for idx, word in enumerate(words):
            if searchWord == word[:len(searchWord)]:
                return idx + 1
        return -1