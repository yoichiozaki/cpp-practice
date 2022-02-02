class MinStack:

    def __init__(self):
        self.q = []

    def push(self, val: int) -> None:
        current_min = self.getMin()
        if current_min is None or val < current_min:
            current_min = val
        self.q.append((val, current_min))

    def pop(self) -> None:
        self.q.pop()

    def top(self) -> int:
        if len(self.q) == 0:
            return None
        else:
            return self.q[-1][0]

    def getMin(self) -> int:
        if len(self.q) == 0:
            return None
        else:
            return self.q[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
