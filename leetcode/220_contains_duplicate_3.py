# TLE: O(n^2)
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if abs(nums[i] - nums[j]) <= t and abs(i - j) <= k:
                    return True
        return False

# O(n)
# -2^31を0として数直線を取り直した上で，幅tで切ったバケツを用意すると
# 同じバケツに入っている数字同士の差は確実にtより小さいのであとはそのバケツの前後を調べれば済む
# バケットソート的なやり方


class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if k < 1 or t < 0:
            return False

        buckets = dict()  # {remapped num: original num}
        MIN_NUM = -(1 << 31)
        for i, num in enumerate(nums):
            remapped = num - MIN_NUM
            bucket = remapped // (t + 1)

            if bucket in buckets or (bucket + 1 in buckets and buckets[bucket + 1] - remapped <= t) or (bucket - 1 in buckets and remapped - buckets[bucket - 1] <= t):
                return True

            if len(buckets) >= k:  # 位置が遠すぎる数字のbucketはいらないので消す
                last_bucket = (nums[i - k] - MIN_NUM) // (t + 1)
                del buckets[last_bucket]
            buckets[bucket] = remapped

        return False
