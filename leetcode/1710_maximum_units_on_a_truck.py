# Greedy
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda box: -box[1])
        boxes = 0
        for box, units in boxTypes:
            if truckSize > box:
                truckSize -= box
                boxes += box * units
            else:
                boxes += truckSize * units
                return boxes
        return boxes