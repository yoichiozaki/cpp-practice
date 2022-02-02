class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        ans = []
        for i in range(len(candies)):
            candies[i] += extraCandies
            ans.append(candies[i] == max(candies))
            candies[i] -= extraCandies
        return ans


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        # extraCandiesを追加したところで元のcandiesの最大値以上になる
        maxCandies = max(candies)
        return [candy + extraCandies >= maxCandies for candy in candies]
