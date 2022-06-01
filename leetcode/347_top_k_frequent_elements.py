# 普通に各数字が何個あるかをカウントしてそれを降順にソートして先頭k個を取ってくる
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        table = dict() # {num: freq}
        for num in nums:
            if num not in table:
                table[num] = 1
            else:
                table[num] += 1
        l = list(table.items())
        l.sort(key=lambda item: item[1], reverse=True)
        ret = [l[i][0] for i in range(k)]
        return ret

# ソートにバケットソートを使うと少し速い
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        
        bucket = [[] for _ in range(len(nums) + 1)]
        for char, freq in counter.items():
            bucket[freq].append(char)

        ans = []
        for pos in range(len(bucket) - 1, -1, -1):
            if len(bucket[pos]) != 0:
                for ch in bucket[pos]:
                    ans.append(ch)
            
        ans = ans[:k]        
        return ans


# quickselect
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        unique = list(count.keys())
        n = len(unique)
        
        # unique[left:right+1]を「unique[pivot]より頻度が少ない」「unique[pivot]と頻度が同じか多い」の二つに分ける
        def partition(unique, left, right, pivot):
            freq = count[unique[pivot]]
            unique[pivot], unique[right] = unique[right], unique[pivot]
            fixed = left
            for i in range(left, right):
                if count[unique[i]] < freq:
                    unique[fixed], unique[i] = unique[i], unique[fixed]
                    fixed += 1
            unique[fixed], unique[right] = unique[right], unique[fixed]
            return fixed
        
        # unique[left:right+1]を前半unique[:target]と後半unique[target:]で頻度が分かれるようにソートする
        def quickselect(unique, left, right, target):
            if left == target:
                return
            idx = partition(unique, left, right, random.randint(left, right))
            if target == idx:
                return
            elif target < idx:
                quickselect(unique, left, idx - 1, target)
            else:
                quickselect(unique, idx + 1, right, target)
            
        quickselect(unique, 0, n - 1, n - k)
        return unique[n - k:]