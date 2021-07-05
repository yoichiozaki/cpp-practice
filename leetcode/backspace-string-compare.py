class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        s = []
        for char in S:
            if char != "#":
                s.append(char)
            else:
                if len(s) != 0:
                    s.pop()
        t = []
        for char in T:
            if char != "#":
                t.append(char)
            else:
                if len(t) != 0:
                    t.pop()
        print(s, t)
        return "".join(s) == "".join(t)


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
