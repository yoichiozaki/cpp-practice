class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        # 答えに対する二分探索
        return bisect_left(
            range(max(ranks) * cars * cars), # 最下位ランクの技術者が全部の車を担当すればもっと遅く仕事が終わる
            cars,
            key=lambda time: sum(floor(math.sqrt(time // rank)) for rank in ranks) # 各ランクの人が time 時間内に処理できる車の台数の和が cars を初めて超える times を二分探索する
        )