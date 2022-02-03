# Time: O(N)
# いわゆる 2 Pointers テクニック．母音だけからなる部分列をleft-rightで目一杯取ったあとにheadをleftから条件を満たす限りジリジリ右に動かしていく
class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        vowel_freq = {"a": 0, "e": 0, "i": 0, "o": 0, "u": 0}
        left = 0
        head = 0
        seen_vowel_kind = 0
        ans = 0
        N = len(word)

        for right in range(N):
            # word[right]が母音
            if word[right] in vowel_freq:
                vowel_freq[word[right]] += 1
                if vowel_freq[word[right]] == 1:
                    seen_vowel_kind += 1
                while seen_vowel_kind == 5:
                    vowel_freq[word[head]] -= 1
                    if vowel_freq[word[head]] == 0:
                        seen_vowel_kind -= 1
                    head += 1
                ans += (head - left)

            # word[right]が子音
            else:
                vowel_freq = {"a": 0, "e": 0, "i": 0, "o": 0, "u": 0}
                seen_vowel_kind = 0
                left = right + 1
                head = right + 1
        return ans
