# 人同士の全組み合わせを調べるとO(len(ages)^2)
# ただ、年齢の組み合わせで考えると、高々年齢は120歳までなのでO(120^2)なら年齢についての2重ループなら許容される
# 解説を見れば理解できるもののそういう発想に問題見てる間にならないのはなぜなのか。手を動かせば自然な発想として出てくるものか？こういうのが「分析的な思考」なんだろうか。。。
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        def can_request(x, y):
            return not (y <= 0.5 * x + 7 or y > x or (y > 100 and x < 100))
        cnt = Counter(ages)
        ans = 0
        for age0 in cnt:
            for age1 in cnt:
                if can_request(age0, age1):
                    if age0 == age1:
                        ans += cnt[age0] * (cnt[age1] - 1)
                    else:
                        ans += cnt[age0] * cnt[age1]
        return ans


class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        ans = 0
        N = len(ages)
        ages.sort()
        for i in range(N):
            age = ages[i]
            idx0 = bisect.bisect(ages, age)
            idx1 = bisect.bisect(ages, 0.5 * age + 7)
            ans += max(0, idx0 - idx1 - 1)
        return ans