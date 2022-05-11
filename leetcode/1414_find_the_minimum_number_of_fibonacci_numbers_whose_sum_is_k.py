# ゼッケンドルフの定理：任意の正の整数は必ず「2個以上の連続しないフィボナッチ数の和」で表すことができる
# 貪欲的に、取れる中で一番大きいフィボナッチ数を引いていくことで必要なフィボナッチ数の個数は計算できる
# 貪欲法が正しいことの証明
# - 連続するフィボナッチ数は答えに含まれない。なぜならそれらは直後の一つのフィボナッチ数で置き換えられるから
# - 同じフィボナッチ数がダブって存在するような解は同じ長さでダブりがない解に変換することができる。なぜならそれらと和が等しい別のフィボナッチ数の組がとれるから
# -> ダブりなく、高々1回までフィボナッチ数を選び出して和kを目指すので貪欲にとっていくのが最適。
# ゼッケンドルフの定理によって解の存在が保証されているなら上記の要領で貪欲にとっていくのがいいと証明できる。
# 硬貨の問題が貪欲法で解けるための条件：https://qiita.com/s417-lama/items/0cdd95fddb2067876896
# 日本の硬貨体系が貪欲法で解けるのはこの条件を満たしているから。すべてのiについてi番目の硬貨とi+1番目の硬貨が割り切れるので条件が成立する。 
class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        if k == 1:
            return 1
        a, b = 1, 1
        while b <= k:
            a, b = b, a + b
        return 1 + self.findMinFibonacciNumbers(k - a)


class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        a, b = 1, 1
        while b <= k:
            a, b = b, a + b
        ret = 0
        while 0 < a:
            if a <= k:
                k -= a
                ret += 1
            a, b = b - a, a
        return ret