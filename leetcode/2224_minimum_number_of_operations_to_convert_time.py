class Solution:
    def convertTime(self, current: str, correct: str) -> int:
        def to_min(s):
            return int(s[0]) * 600 + int(s[1]) * 60 + int(s[3]) * 10 + int(s[4])
        d = to_min(correct) - to_min(current)
        return d // 60 + d % 60 // 15 + d % 15 // 5 + d % 5

        