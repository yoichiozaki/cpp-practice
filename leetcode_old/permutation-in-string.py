# Blute-force
# s1の順列を全部求めてそれがs2に存在するかを調べる
# Time: O(len(s1)!)
# Space: O(len(s1)^2)
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        flag = False

        def permutation(s, sofar):
            nonlocal flag
            if len(s) == 0:
                if sofar in s2:
                    flag = True
                return
            for i in range(len(s)):
                permutation(s[:i] + s[i+1:], sofar + s[i])

        permutation(s1, "")
        return flag


# Sorting
# s1の順列が存在するか否か判定するだけなので，実際のどの順列が存在するかは今は不要
# なので，s1と同じ文字種が同じ個数存在するかを確認すれば十分
# s2の長さlen(s1)の部分列をソートした結果がs1をソートしたものと同じかどうかを確認すれば良い
# l1 = len(s1), l2 = len(s2)
# Time: O(l1 log l1 + (l2 - l1) * l1 log l1)
# Space: ソートアルゴリズム依存
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        s1 = "".join(sorted(s1))
        for i in range(len(s2) - len(s1) + 1):
            if s1 == "".join(sorted(s2[i:i+len(s1)])):
                return True
        return False


# Map
# 基本的にはソートを使う解き方と同じ考え方．「s1と同じ文字種が同じ個数存在するか」を辞書の比較で実現
# l1 = len(s1), l2 = len(s2)
# Time: O(l1 + (l2 - l1) * l1)
# Space: O(l1 + l2)
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        cnt1 = Counter(s1)
        for i in range(len(s2) - len(s1) + 1):
            cnt2 = Counter()
            for j in range(len(s1)):
                if s2[i + j] in cnt2:
                    cnt2[s2[i + j]] += 1
                else:
                    cnt2[s2[i + j]] = 1
            if cnt1 == cnt2:
                return True
        return False


# Array
# Mapと同じことを配列で行う．indexがkeyになる．
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        cnt1 = [0 for _ in range(26)]
        for ch in s1:
            cnt1[ord(ch) - ord('a')] += 1

        for i in range(len(s2) - len(s1) + 1):
            cnt2 = [0 for _ in range(26)]
            for ch in s2[i:i+len(s1)]:
                cnt2[ord(ch) - ord('a')] += 1

            flag = True
            for i in range(26):
                if cnt1[i] != cnt2[i]:
                    flag = False
                    break
            if flag:
                return True
        return False


# Sliding window
# 毎回ゼロから「どの文字種が何個ある」の配列（or辞書）を作るのは無駄が多い
# iが一つずれたときのcnt2は一つ前からの差分で効率よく作れる
# Time: O(l1 + (l2 - l1) * 26)
# Space: O(1)
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        cnt1 = [0 for _ in range(26)]
        cnt2 = [0 for _ in range(26)]
        for i in range(len(s1)):
            ch = s1[i]
            cnt1[ord(ch) - ord('a')] += 1
            ch = s2[i]
            cnt2[ord(ch) - ord('a')] += 1

        def match(cnt1, cnt2):
            for i in range(26):
                if cnt1[i] != cnt2[i]:
                    return False
            return True

        for i in range(len(s2) - len(s1)):
            if match(cnt1, cnt2):
                return True

            left = s2[i]
            right = s2[i + len(s1)]
            cnt2[ord(left) - ord('a')] -= 1
            cnt2[ord(right) - ord('a')] += 1

        return match(cnt1, cnt2)


# 一つ前の解法を改良
# cnt1とcnt2が一致しているのをもっと効率良く調べる
# Time: O(l1 + (l2 - l1))
# Space: O(1)
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        cnt1 = [0 for _ in range(26)]
        cnt2 = [0 for _ in range(26)]
        for i in range(len(s1)):
            ch = s1[i]
            cnt1[ord(ch) - ord('a')] += 1
            ch = s2[i]
            cnt2[ord(ch) - ord('a')] += 1

        matched = 0
        for i in range(26):
            if cnt1[i] == cnt2[i]:
                matched += 1

        for i in range(len(s2) - len(s1)):
            left = ord(s2[i]) - ord('a')
            right = ord(s2[i + len(s1)]) - ord('a')

            if matched == 26:
                return True

            cnt2[left] -= 1
            if cnt2[left] == cnt1[left]:
                matched += 1
            elif cnt2[left] + 1 == cnt1[left]:
                matched -= 1

            cnt2[right] += 1
            if cnt2[right] == cnt1[right]:
                matched += 1
            elif cnt2[right] - 1 == cnt1[right]:
                matched -= 1

        return matched == 26
