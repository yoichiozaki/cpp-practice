class Solution:
    def capitalizeTitle(self, title: str) -> str:
        title = title.lower()
        ans = ""
        for t in title.split():
            if len(t) <= 2:
                ans += t + " "
            else:
                ans += chr(ord("A") + (ord(t[0]) - ord("a"))) + t[1:] + " "
        return ans[:-1]
