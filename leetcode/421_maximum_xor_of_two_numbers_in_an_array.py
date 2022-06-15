class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        ans = 0
        for i in range(31, -1, -1):
            ans <<= 1
            prefixes = {num >> i for num in nums}
            ans |= any(ans ^ 1 ^ prefix in prefixes for prefix in prefixes)
        return ans


# 左から右へ桁を埋めていく。forループの途中のansは複数のペアの結果を重ね合わせた状態になっているイメージ。埋まる桁が増えていくにしたがって重ね合わせが解けていく。
# Trie木を作って根からできるだけ多く1を通るように走査するとかもある？