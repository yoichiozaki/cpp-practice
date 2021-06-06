class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        not_visited_yet = set(wordList)
        suspended = list()

        not_visited_yet.add(beginWord)
        suspended.append((beginWord, 1))

        while len(suspended) != 0:
            word, length = suspended.pop(0)
            if word == endWord:
                return length
            for i in range(len(word)):
                for char in 'abcdefghijklmnopqrstuvwxyz':
                    next_candidate = word[:i] + char + word[i+1:]
                    if next_candidate in not_visited_yet:
                        not_visited_yet.remove(next_candidate)
                        suspended.append((next_candidate, length + 1))
        return 0
