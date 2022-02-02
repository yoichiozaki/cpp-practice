class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        ans = []
        first_ptr = 0
        second_ptr = 0

        while first_ptr < len(firstList) and second_ptr < len(secondList):
            start = max(firstList[first_ptr][0], secondList[second_ptr][0])
            end = min(firstList[first_ptr][1], secondList[second_ptr][1])

            if start <= end:
                ans.append([start, end])

            if firstList[first_ptr][1] < secondList[second_ptr][1]:
                first_ptr += 1
            else:
                second_ptr += 1

        return ans
