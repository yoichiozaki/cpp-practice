# Trie木で数字を管理しながら，それぞれの数字に対して最大のXORを与える数字を効率良く見つける
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        class TrieTreeNode:
            def __init__(self):
                self.children = dict()
                self.go = 0

            def insert(self, number):
                current = self
                for i in range(31, -1, -1):
                    bit = (number >> i) & 1
                    if bit not in current.children:
                        current.children[bit] = TrieTreeNode()
                    current = current.children[bit]
                    current.go += 1

            def find_xor_max(self, number):
                current = self
                xor_max = 0
                for i in range(31, -1, -1):
                    bit = (number >> i) & 1
                    if (1 - bit) in current.children and 0 < current.children[1 - bit].go:
                        current = current.children[1 - bit]
                        xor_max |= (1 << i)
                    else:
                        current = current.children[bit]
                return xor_max

        trie = TrieTreeNode()
        for num in nums:
            trie.insert(num)
        xor_max = 0
        for num in nums:
            xor_max = max(xor_max, trie.find_xor_max(num))
        return xor_max


# hacky way
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        answer = 0
        for i in range(32)[::-1]:
            answer <<= 1
            prefixes = {num >> i for num in nums}
            answer += any(answer ^ 1 ^ p in prefixes for p in prefixes)
        return answer
