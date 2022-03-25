# blute-force
# Time: O(n^2)
# Space: O(1)
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = []
        n = len(nums)
        for i in range(n):
            prod = 1
            for j in range(n):
                if j != i:
                    prod *= nums[j]
            ans.append(prod)
        return ans


# accumurated product and divide by self
# Time: O(n)
# Space: O(1)
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prod = reduce(lambda a, b: a*(b if b != 0 else 1), nums, 1)
        zeros = nums.count(0)
        n = len(nums)
        ans = [0 for _ in range(n)]
        if 2 <= zeros:
            return ans
        for i, num in enumerate(nums):
            if zeros != 0:
                if num == 0:
                    ans[i] = prod
            else:
                ans[i] = prod // num
        return ans


# prefix & suffix product
# Time: O(n)
# Space: O(n)
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix_products = list(accumulate(nums, mul))
        suffix_products = list(accumulate(nums[::-1], mul))[::-1]
        n = len(nums)
        return [(prefix_products[i-1] if i != 0 else 1) * (suffix_products[i + 1] if i + 1 < n else 1) for i in range(n)]


# space-optimized prefix & suffix product
# Time: O(n)
# Space: O(1)
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = []
        accum = 1
        N = len(nums)
        for i in range(N):
            ans.append(accum)
            accum *= nums[i]
        accum = 1
        for i in range(N-1, -1, -1):
            ans[i] = accum * ans[i]
            accum *= nums[i]
        return ans
