# 連続する部分和についての問題なので累積和が有効。さらに言えば注目しているのは連続する部分和をkで割ったあまりが等しければ良い。
# 先頭から見ていく部分列を伸ばしながら、それより短い部分列の和のkで割ったあまりを知れればいいのでO(n)になる
# 逆に言えば、ある長さの部分列に注目している段階で、それより長い部分列の話は要らない
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        ans = 0
        mod = 0
        cnt = [1] + [0 for _ in range(k - 1)]
        for num in nums:
            mod = (mod + num) % k
            ans += cnt[mod]
            cnt[mod] += 1
        return ans