# 辞書2つ
class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        freq1 = dict()
        for word in words1:
            if word not in freq1:
                freq1[word] = 1
            else:
                freq1[word] += 1
        freq2 = dict()
        for word in words2:
            if word not in freq2:
                freq2[word] = 1
            else:
                freq2[word] += 1
        ans = 0
        for k, v in freq1.items():
            if v == 1 and k in freq2 and freq2[k] == 1:
                ans += 1
        return ans


# 辞書1つ．一方で2回以上出てくるやつは無視できる
class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        freq = dict()
        for word in words1:
            if word not in freq:
                freq[word] = 1
            else:
                freq[word] += 1
        for word in words2:
            if word in freq and freq[word] < 2:
                freq[word] -= 1
        ans = 0
        for v in freq.values():
            if v == 0:
                ans += 1
        return ans


class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        freq1 = Counter(words1)
        freq2 = Counter(words2)
        return sum(freq1[key] == freq2[key] == 1 for key in freq1)
