# 貪欲法：一つの部分文字列に同じ文字が含まれてはいけないので、冒頭から文字列を眺めて、すでに観測済みの文字列に遭遇したらそこで部分文字列が確定する
class Solution:
    def partitionString(self, s: str) -> int:
        bitmask = 0
        def is_already_there(ch):
            shift = ord(ch) - ord('a')
            return bitmask & (1 << shift) != 0
        ans = 1
        for ch in s:
            if is_already_there(ch):
                ans += 1
                shift = ord(ch) - ord('a')
                bitmask = 1 << shift
            else:
                shift = ord(ch) - ord('a')
                bitmask = bitmask | (1 << shift)
        return ans