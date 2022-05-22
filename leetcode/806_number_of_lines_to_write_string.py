class Solution:
    def numberOfLines(self, widths: List[int], s: str) -> List[int]:
        lines = 1
        width = 0
        for ch in s:
            if width + widths[ord(ch) - ord('a')] > 100:
                lines += 1
                width = widths[ord(ch) - ord('a')]
            else:
                width += widths[ord(ch) - ord('a')]
        return [lines, width]