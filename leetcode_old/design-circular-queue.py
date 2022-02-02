class MyCircularQueue:

    def __init__(self, k: int):
        self.length = 0
        self.max_length = k
        self.front = -1
        self.rear = -1
        self.queue = [None for _ in range(k)]

    def enQueue(self, value: int) -> bool:
        if self.isFull():
            return False
        else:
            if self.rear == -1:
                self.front = 0
                self.rear = 0
            else:
                self.rear = (self.rear + 1) % self.max_length
            self.queue[self.rear] = value
            self.length += 1
            return True

    def deQueue(self) -> bool:
        if self.isEmpty():
            return False
        else:
            if self.front == self.rear:
                self.front = -1
                self.rear = -1
            else:
                self.front = (self.front + 1) % self.max_length
            self.length -= 1
            return True

    def Front(self) -> int:
        return self.queue[self.front] if not self.isEmpty() else -1

    def Rear(self) -> int:
        return self.queue[self.rear] if not self.isEmpty() else -1

    def isEmpty(self) -> bool:
        return self.length == 0

    def isFull(self) -> bool:
        return self.length == self.max_length


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
