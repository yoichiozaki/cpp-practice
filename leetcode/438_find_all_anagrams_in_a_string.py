class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p) > len(s):
            return []
        cnt1 = [0 for _ in range(26)]
        cnt2 = [0 for _ in range(26)]
        for i in range(len(p)):
            cnt1[ord(p[i]) - ord('a')] += 1
            cnt2[ord(s[i]) - ord('a')] += 1
        def matches(cnt1, cnt2):
            for i in range(26):
                if cnt1[i] != cnt2[i]:
                    return False
            return True
        ans = []
        for i in range(len(s) - len(p)):
            if matches(cnt1, cnt2):
                ans.append(i)
            cnt2[ord(s[i + len(p)]) - ord('a')] += 1
            cnt2[ord(s[i]) - ord('a')] -= 1
        if matches(cnt1, cnt2):
            ans.append(len(s) - len(p))
        return ans
        