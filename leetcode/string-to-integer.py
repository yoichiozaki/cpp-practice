class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.strip()
        int_part = ""
        for char in s:
            if char == ".":
                break  # 123.4...
            if char.isdigit() or char in ["+", "-"]:
                if char in ["+", "-"] and 0 < len(int_part):
                    break  # 12345+...
                int_part += char
            else:
                break  # char is alphabet
        ans = 0
        digit = 0
        for char in int_part[::-1]:
            if char == "-":
                ans *= -1  # -123
            elif char == "+":
                continue  # +123
            else:
                ans += int(char) * (10 ** digit)
                digit += 1
        if -2 ** 31 <= ans and ans < 2 ** 31:
            return ans
        elif ans < -2 ** 31:
            return -2 ** 31
        else:
            return 2 ** 31 - 1
