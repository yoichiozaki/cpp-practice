# 一番多く登場するタスクで全体の終了が律速される。一番多く登場するタスクをこなす間にほかのタスクを入れていけばよい。一番多く登場するタスクが複数ある場合は互いに交互に（縫い目みたいに）やればタスク間のアイドルを確保できる。
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        tasks_count = list(Counter(tasks).values())
        max_count = max(tasks_count)
        max_count_tasks = tasks_count.count(max_count)
        return max(len(tasks), (max_count - 1) * (n + 1) + max_count_tasks)