from collections import deque

class LRUCache:

    def __init__(self, capacity: int):
        self.cache = dict()
        self.capacity = capacity
        self.lru = deque()
        

    def get(self, key: int) -> int:
        if key in self.cache.keys():
            self.lru.remove(key)
            self.lru.append(key)
            return self.cache[key]
        else:
            return -1


    def put(self, key: int, value: int) -> None:
        if key in self.cache.keys():
            self.cache[key] = value
            self.lru.remove(key)
            self.lru.append(key)
            return
        if len(self.cache.keys()) == self.capacity:
            to_be_deleted = self.lru.popleft()
            del self.cache[to_be_deleted]
            self.cache[key] = value
            self.lru.append(key)
        else:
            self.cache[key] = value
            self.lru.append(key)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)