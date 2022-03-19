class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def process(s):
            stack = []
            for ch in s:
                if ch != "#":
                    stack.append(ch)
                elif len(stack) != 0:
                    stack.pop()
            return "".join(stack)
        return process(s) == process(t)


class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def f(S):
            skip = 0
            for x in reversed(S):
                if x == '#':
                    skip += 1
                elif skip != 0:
                    skip -= 1
                else:
                    yield x
        return all(x == y for x, y in itertools.zip_longest(f(s), f(t)))
