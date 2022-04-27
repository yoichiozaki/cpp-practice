class MyHashSet:

    def __init__(self):
        self.storage = [[] for _ in range(1 << 15)]

    def _hash(self, key):
        return (key * 1031237) & ((1 << 20) - 1) >> 5
    
    def add(self, key: int) -> None:
        hashed = self._hash(key)
        if key not in self.storage[hashed]:
            self.storage[hashed].append(key)

    def remove(self, key: int) -> None:
        hashed = self._hash(key)
        if key in self.storage[hashed]:
            self.storage[hashed].remove(key)

    def contains(self, key: int) -> bool:
        hashed = self._hash(key)
        return key in self.storage[hashed]


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)