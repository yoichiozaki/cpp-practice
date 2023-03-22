class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        total_surplus = 0
        surplus = 0
        start = 0
        for i in range(len(gas)):
            total_surplus += gas[i] - cost[i]
            surplus += gas[i] - cost[i]
            if surplus < 0:
                surplus = 0
                start = i + 1
        if total_surplus < 0:
            return -1
        return start
    

# どうせ1周するので、途中までの結果を残しておけば無駄な計算が減らせる