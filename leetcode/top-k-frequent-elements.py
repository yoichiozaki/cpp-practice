# 長さkのheapを使う
# Time: O(n log k)
# Space: O(n + k)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = [(freq, num) for num, freq in Counter(nums).items()]
        return [num for _, num in heapq.nlargest(k, cnt)]


# k番目に大きい値を二分探索みたいに見つける
# partitioningを行うことで配列の後ろの方にk個大きいやつが貯まる
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        def partition(left, right, pivot_index):
            pivot_frequency = count[unique[pivot_index]]
            unique[pivot_index], unique[right] = unique[right], unique[pivot_index]

            store_index = left
            for i in range(left, right):
                if count[unique[i]] < pivot_frequency:
                    unique[store_index], unique[i] = unique[i], unique[store_index]
                    store_index += 1

            unique[right], unique[store_index] = unique[store_index], unique[right]

            return store_index

        def quickselect(left, right, k_smallest):
            if left == right:
                return

            pivot_index = random.randint(left, right)
            pivot_index = partition(left, right, pivot_index)

            if k_smallest == pivot_index:
                return
            elif k_smallest < pivot_index:
                quickselect(left, pivot_index - 1, k_smallest)
            else:
                quickselect(pivot_index + 1, right, k_smallest)

        count = Counter(nums)
        unique = list(count.keys())
        n = len(unique)
        quickselect(0, n - 1, n - k)
        return unique[n - k:]
