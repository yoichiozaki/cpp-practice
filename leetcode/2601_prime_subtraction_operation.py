class Solution:
    def primeSubOperation(self, nums: List[int]) -> bool:
        MAX = 1005
        is_prime = [True for _ in range(MAX)]
        is_prime[0] = False
        is_prime[1] = False
        
        i = 2
        while i * i < MAX:
            if is_prime[i]:
                j = i * i
                while j < MAX:
                    is_prime[j] = False
                    j += i
            i += 1
        
        primes = []
        for i in range(2, 1001):
            if is_prime[i]:
                primes.append(i)
        
        N = len(nums)
        new_nums = [num for num in nums]
        for i in range(N - 2, -1, -1):
            if (nums[i] < new_nums[i + 1]):
                new_nums[i] = nums[i]
                continue
            else:
                for prime in primes:
                    if prime >= nums[i]:
                        new_nums[i] = nums[i]
                        break
                    if nums[i] - prime < new_nums[i+1]:
                        new_nums[i] = nums[i] - prime
                        break
        for i in range(1, N):
            if new_nums[i] <= new_nums[i-1]:
                return False
        return True