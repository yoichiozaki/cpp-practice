# Blute-force
class Solution:
    def longestWord(self, words: List[str]) -> str:
        ans = ""
        words = set(words)
        for word in words:
            if len(ans) < len(word) or len(ans) == len(word) and word < ans:
                if all(word[:k] in words for k in range(1, len(word))):
                    ans = word
        return ans


# Trie木上のDFS
class Solution:
    def longestWord(self, words: List[str]) -> str:
        class TrieNode:
            def __init__(self, ch):
                self.ch = ch
                self.children = dict()
                self.index = -1  # 1-indexed

        class TrieTree:
            def __init__(self):
                self.root = TrieNode("#")
                self.words = []

            def insert(self, word, index):
                curr = self.root
                for ch in word:
                    if ch not in curr.children:
                        curr.children[ch] = TrieNode(ch)
                    curr = curr.children[ch]
                curr.index = index

            def dfs(self):
                ans = ""
                stack = [self.root]
                while len(stack) != 0:
                    node = stack.pop()
                    if 0 < node.index or node == self.root:
                        if node is not self.root:
                            word = words[node.index - 1]
                            if len(ans) < len(word) or len(ans) == len(word) and word < ans:
                                ans = word
                        for child in node.children.values():
                            stack.append(child)
                return ans

        trie = TrieTree()
        for index, word in enumerate(words):
            trie.insert(word, index + 1)
        trie.words = words
        return trie.dfs()
