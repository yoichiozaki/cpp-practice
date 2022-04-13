class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ans = []
        def rec(s, idx, sofar):
            if idx > 4:
                return
            if idx == 4 and s == "":
                ans.append(sofar[:-1])
                return
            for i in range(1, len(s) + 1):
                if s[:i] == "0" or (s[0] != "0" and 0 < int(s[:i]) <= 255):
                    rec(s[i:], idx + 1, sofar + s[:i] + ".")
        rec(s, 0, "")
        return ans