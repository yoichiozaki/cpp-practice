# 各要素の最大値を取るので、targetの要素より大きい要素を含むtripletはmergeしちゃいけない
# 結局最大値を取ることでmergeしちゃうのでいくつか選んでmergeするのと全部mergeしちゃうのは同じ結果になる
class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        a = b = c = 0
        for [x, y, z] in triplets:
            if x <= target[0] and y <= target[1] and z <= target[2]:
                a = max(a, x)
                b = max(b, y)
                c = max(c, z)
        return [a, b, c] == target