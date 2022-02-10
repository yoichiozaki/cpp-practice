class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        need = 1 << k
        found = set()
        for i in range(k, len(s) + 1, 1):
            t = s[i-k:i]
            if t not in found:
                found.add(t)
                need -= 1
                if need == 0:
                    return True
        return False


class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        need = 1 << k
        found = [False for _ in range(need)]
        all_ones = need - 1
        hash_val = 0
        for i in range(len(s)):
            hash_val = ((hash_val << 1) & all_ones) | int(s[i])
            if k-1 <= i and found[hash_val] == False:
                found[hash_val] = True
                need -= 1
                if need == 0:
                    return True
        return False
