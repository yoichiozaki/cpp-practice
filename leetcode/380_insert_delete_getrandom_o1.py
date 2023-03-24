import random

class RandomizedSet:

    def __init__(self):
        self.dct = dict()
        self.lst = list()
        
    def insert(self, val: int) -> bool:
        if val in self.dct:
            return False
        self.dct[val] = len(self.lst)
        self.lst.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.dct:
            return False
        last_element, pos = self.lst[-1], self.dct[val]
        self.lst[pos], self.dct[last_element] = last_element, pos
        self.lst.pop()
        del self.dct[val]
        return True

    def getRandom(self) -> int:
        return random.choice(self.lst)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()

# removeして空いた個所を埋めるのに、後続の要素を全部ひとつ前に移動するのではなくて、末尾の要素を空いたところに移動させるというアイディア