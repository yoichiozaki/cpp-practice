class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        def longest_substring(s, ch, k):
            left = 0
            for right in range(len(s)):
                if s[right] != ch:
                    k -= 1
                if k < 0:
                    if s[left] != ch:
                        k += 1
                    left += 1
            return right - left + 1
        return max(longest_substring(answerKey, "T", k), longest_substring(answerKey, "F", k))
                    