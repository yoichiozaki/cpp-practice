class Solution:
    def calculate(self, s: str) -> int:
        if s == "":
            return 0
        stack = []
        num = 0
        sign = "+"
        for i in range(len(s)):
            if s[i].isdigit():
                num = num * 10 + (ord(s[i]) - ord('0'))
            if (not s[i].isdigit() and not s[i].isspace()) or i == len(s) - 1:
                if sign == "-":
                    stack.append(-num)
                elif sign == "+":
                    stack.append(+num)
                elif sign == "*":
                    stack.append(stack.pop() * num)
                elif sign == "/":
                    top = stack.pop()
                    if top // num < 0 and top % num != 0:
                        stack.append(top // num + 1)
                    else:
                        stack.append(top // num)
                sign = s[i]
                num = 0
        return sum(stack)