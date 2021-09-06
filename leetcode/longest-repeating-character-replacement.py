class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = [0 for _ in range(26)]
        left = 0
        max_count = 0
        max_length = 0
        for right in range(len(s)):
            count[ord(s[right]) - ord('A')] += 1
            if max_count < count[ord(s[right]) - ord('A')]:
                max_count = count[ord(s[right]) - ord('A')]
            while k < right - left - max_count + 1:
                count[ord(s[left]) - ord('A')] -= 1
                left += 1
                max_count = max(count)
            max_length = max(max_length, right - left + 1)
        return max_length
