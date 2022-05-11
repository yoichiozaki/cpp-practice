class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        hardest = max(milestones)
        remains = sum(milestones) - hardest
        if hardest > remains:
            return remains * 2 + 1
        else:
            return hardest + remains