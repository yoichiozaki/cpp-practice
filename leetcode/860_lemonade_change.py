class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        five = 0
        ten = 0
        for bill in bills:
            if bill == 5:
                five += 1
            if bill == 10:
                if five == 0:
                    return False
                five -= 1
                ten += 1
            if bill == 20:
                if not (five >= 3 or (five >= 1 and ten >= 1)):
                    return False
                if five >= 1 and ten >= 1:
                    five -= 1
                    ten -= 1
                else:
                    five -= 3
        return True
                