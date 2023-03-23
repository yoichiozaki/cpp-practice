class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token == "+":
                num2 = stack.pop()
                num1 = stack.pop()
                stack.append(num1 + num2)
            elif token == "-":
                num2 = stack.pop()
                num1 = stack.pop()
                stack.append(num1 - num2)
            elif token == "*":
                num2 = stack.pop()
                num1 = stack.pop()
                stack.append(num1 * num2)
            elif token == "/":
                num2 = stack.pop()
                num1 = stack.pop()
                num = num1 // num2
                if num1 // num2 < 0 and num1 % num2 != 0:
                    num += 1
                stack.append(num)
            else:
                stack.append(int(token))
        return stack.pop()