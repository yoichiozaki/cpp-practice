class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans = -1
        min_sofar = float("inf")
        for num in nums:
            min_sofar = min(min_sofar, num)
            if min_sofar < num:
                ans = max(ans, num - min_sofar)
        return ans


class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        import itertools
        min_scan = itertools.accumulate(
            nums,
            min,
            initial=float("+inf")
        )

        min_scan = list(min_scan)[1:]

        zipped = zip(nums, min_scan)

        mapped = map(lambda _: _[0] - _[1], zipped)

        filtered = filter(lambda _: _ != 0, mapped)

        import functools
        def fold_left(func, acc, xs): return functools.reduce(func, xs, acc)
        ans = fold_left(max, -1, filtered)

        return ans

# in Scala
# def maximumDifference(nums: Array[Int]): Int =
#     nums.scanLeft(Int.MaxValue)(_ min _)
#         .tail
#         .zip(nums)
#         .map(x => x._2 - x._1)
#         .filter(_ != 0)
#         .foldLeft(-1)(_ max _)
