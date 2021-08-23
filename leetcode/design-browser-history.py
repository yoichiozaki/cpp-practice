class BrowserHistory:

    def __init__(self, homepage: str):
        self.past = [homepage]
        self.future = []

    def visit(self, url: str) -> None:
        self.past.append(url)
        self.future = []

    def back(self, steps: int) -> str:
        while 0 < steps and 1 < len(self.past):
            self.future.append(self.past.pop())
            steps -= 1
        return self.past[-1]

    def forward(self, steps: int) -> str:
        while 0 < steps and 0 < len(self.future):
            self.past.append(self.future.pop())
            steps -= 1
        return self.past[-1]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
