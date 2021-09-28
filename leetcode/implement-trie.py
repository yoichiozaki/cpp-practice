# Trie木
# https://ja.wikipedia.org/wiki/Trie

class TrieNode:

    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_terminal = False


class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for char in word:
            node = node.children[char]
        node.is_terminal = True

    def search(self, word: str) -> bool:
        node = self.root
        for char in word:
            node = node.children.get(char)
            if node is None:
                return False
        return node.is_terminal

    def startsWith(self, prefix: str) -> bool:
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
