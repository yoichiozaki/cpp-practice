class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        if len(nums) == 0:
            return []
        
        candidate0 = 0
        count0 = 0
        candidate1 = 1
        count1 = 0
        for num in nums:
            if num == candidate0:
                count0 += 1
            elif num == candidate1:
                count1 += 1
            elif count0 == 0:
                candidate0 = num
                count0 = 1
            elif count1 == 0:
                candidate1 = num
                count1 = 1
            else:
                count0 -= 1
                count1 -= 1
        return [num for num in (candidate0, candidate1) if nums.count(num) > len(nums) // 3]
    
    # Boyer-Moore法：ソートされていない配列の過半数を超える要素があるかを O(N) で計算するアルゴリズム
    