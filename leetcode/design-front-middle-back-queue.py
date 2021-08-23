class FrontMiddleBackQueue:

    def __init__(self):
        self.data = []

    def pushFront(self, val: int) -> None:
        self.data = [val] + self.data

    def pushMiddle(self, val: int) -> None:
        if len(self.data) % 2 == 0:
            self.data.insert(len(self.data) // 2, val)
        else:
            self.data.insert(len(self.data) // 2, val)

    def pushBack(self, val: int) -> None:
        self.data = self.data + [val]

    def popFront(self) -> int:
        if len(self.data) == 0:
            return -1
        return self.data.pop(0)

    def popMiddle(self) -> int:
        if len(self.data) == 0:
            return -1
        if len(self.data) % 2 == 0:
            return self.data.pop(len(self.data) // 2 - 1)
        else:
            return self.data.pop(len(self.data) // 2)

    def popBack(self) -> int:
        if len(self.data) == 0:
            return -1
        return self.data.pop()


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()


class FrontMiddleBackQueue:

    def __init__(self):
        self.fronthalf = collections.deque()
        self.backhalf = collections.deque()

    def pushFront(self, val: int) -> None:
        self.fronthalf.appendleft(val)
        self.balance()

    def pushMiddle(self, val: int) -> None:
        if len(self.fronthalf) > len(self.backhalf):
            self.backhalf.appendleft(self.fronthalf.pop())
        self.fronthalf.append(val)

    def pushBack(self, val: int) -> None:
        self.backhalf.append(val)
        self.balance()

    def popFront(self) -> int:
        ret = self.fronthalf.popleft() if self.fronthalf else -1
        self.balance()
        return ret

    def popMiddle(self) -> int:
        ret = (self.fronthalf or [-1]).pop()
        self.balance()
        return ret

    def popBack(self) -> int:
        ret = (self.backhalf or self.fronthalf or [-1]).pop()
        self.balance()
        return ret

    def balance(self) -> None:
        # keep len(self.fronthalf) >= len(self.backhalf)
        if len(self.fronthalf) > len(self.backhalf) + 1:
            self.backhalf.appendleft(self.fronthalf.pop())
        if len(self.fronthalf) < len(self.backhalf):
            self.fronthalf.append(self.backhalf.popleft())

# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()
