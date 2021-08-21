# dutch partitioning problem
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        RED = 0
        WHITE = 1
        BLUE = 2

        red = 0
        white = 0
        blue = len(nums) - 1
        while white <= blue:
            if nums[white] == RED:
                nums[red], nums[white] = nums[white], nums[red]
                red += 1
                white += 1
            elif nums[white] == WHITE:
                white += 1
            else:  # nums[white] == BLUE
                nums[blue], nums[white] = nums[white], nums[blue]
                blue -= 1


# hacky way
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort()
