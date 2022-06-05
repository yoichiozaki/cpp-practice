class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        cnt1 = [0 for _ in range(26)]
        cnt2 = [0 for _ in range(26)]
        for i in range(len(s1)):
            cnt1[ord(s1[i]) -  ord('a')] += 1
            cnt2[ord(s2[i]) -  ord('a')] += 1
        def matches(cnt1, cnt2):
            for i in range(26):
                if cnt1[i] != cnt2[i]:
                    return False
            return True
        for i in range(len(s2) - len(s1)):
            if matches(cnt1, cnt2):
                return True
            cnt2[ord(s2[i + len(s1)]) - ord('a')] += 1
            cnt2[ord(s2[i]) - ord('a')] -= 1
        return matches(cnt1, cnt2)
        
