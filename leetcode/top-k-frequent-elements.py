class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        cnt = [(freq, num) for num, freq in Counter(nums).items()]
        return [num for _, num in heapq.nlargest(k, cnt)]
